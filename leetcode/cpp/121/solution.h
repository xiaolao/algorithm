// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//  

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.
//  

// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 104

#include <vector>
#include <algorithm>

using std::max;
using std::vector;


class Solution {
public:
    // 定义状态dp[i]为第i天卖出股票时获得的最大收益。
    // 则有dp[i] = max(0, dp[i-1]+prices[i]-prices[i-1]);
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int res = 0, mp = 0;
        for (int i = 0; i < n; ++i) {
            mp = max(0, mp+prices[i]-prices[i-1]);
            res = max(res, mp);
        }
        return res;
    }
};
