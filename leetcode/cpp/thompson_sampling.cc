#include <algorithm>
#include <boost/random.hpp>
#include <boost/random/beta_distribution.hpp>
#include <boost/random/discrete_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ostream>
#include <random>
#include <vector>

using boost::random::beta_distribution;
using boost::random::discrete_distribution;

template<class T>
size_t argmax(const std::vector<T>& v) {
    return std::distance(v.begin(), std::max_element(v.begin(), v.end()));
}

// pull_lever has a chance of 1/weight of returning 1.
unsigned int pull_level(boost::mt19937 *rand_, double weight) {
    double probabilities[] = {1-weight, weight};
    discrete_distribution<> dist(probabilities);
    return dist(*rand_);
    
}

int main(int argc, char* argv[]) {
    unsigned int runs = 100;

    // Probability of winning for each bandit. Change this variable to experiment
    // with different probabilities of winning.
    std::vector<double> p{0.50, 0.53, 0.55};

    // Number of trials per bandit
    auto trails = std::vector<unsigned int>(p.size());
    // Number of wins per bandif
    auto wins = std::vector<unsigned int>(p.size());

    // Beta distributions of the priors for each bandit
    std::vector<beta_distribution<>> beta_dists;

    // Initialize the prior distributions with alpha=1 beta=1
    for (size_t i = 0; i < p.size(); i++) {
        beta_dists.push_back(beta_distribution<>(1, 1));
    }

    std::random_device rd;
    boost::mt19937 rand_;
    rand_.seed(rd());

    // 探索胜率最高的老虎机
    // 探索出点击率最高的素材
    for (unsigned int i = 0; i < runs; i++) {
        std::vector<double> priors;

        for (auto& dist : beta_dists) {
            priors.push_back(dist(rand_));
        }
        // Select the bandit that has the highest sampled value from the prior
        size_t chosen_bandit = argmax(priors);
        trails[chosen_bandit]++;
        // Pull the lever of the chosen bandit
        wins[chosen_bandit] += pull_level(&rand_, p[chosen_bandit]);

        auto alpha = 1 + wins[chosen_bandit];
        auto beta = 1 + trails[chosen_bandit] - wins[chosen_bandit];
        beta_dists[chosen_bandit] = beta_distribution<>(alpha, beta);
    }

    auto sp = std::cout.precision();
    std::cout << std::setprecision(6);

    for (size_t i = 0; i < p.size(); i++) {
        std::cout << "Bandit " << i + 1 << ": ";
        double empirical_p = double(wins[i]) / trails[i];
        std::cout << "wins/trials: " << wins[i] << "/" << trails[i] << ". ";
        std::cout << "Estimate p: " << empirical_p << " ";
        std::cout << "Actual p: " << p[i] << std::endl;
    }

    std::cout << std::endl;
    auto expected_optimal_wins = *std::max_element(p.begin(), p.end()) * runs;
    std::cout << std::setprecision(sp);
    std::cout << "Expected number of wins with optimal strategy: " << expected_optimal_wins << std::endl;
    std::cout << "Actual wins: " << std::accumulate(wins.begin(), wins.end(), 0) << std::endl;
}
