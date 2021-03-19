// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
// Example 2:

// Input: prices = [1,3,7,5,10,3], fee = 3
// Output: 6
 

// Constraints:

// 1 < prices.length <= 5 * 104
// 0 < prices[i], fee < 5 * 104

#include <vector>
#include <algorithm>

using std::max;
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // 对于第i天结束后有两种状态，持有和不持有股票
        // 分别使用buy[i],sell[i]表示第i天结束后两种状态的最大收益
        // buy[i] = max(buy[i-1], sell[i-1]-prices[i]);
        // sell[i] = max(buy[i-1], sell[i-1]+prices[i]);
        int n = prices.size();
        if (n < 2) return 0;
        int buy = -prices[0], sell = 0;
        for (int i = 0; i < n; i++) {
            buy = max(buy, sell-prices[i]);
            sell = max(sell, buy+prices[i]-fee);
        }
        return sell;
    }
};
