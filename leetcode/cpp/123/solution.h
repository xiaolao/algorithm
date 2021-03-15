// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

//  

// Example 1:

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
// Example 4:

// Input: prices = [1]
// Output: 0
//  

// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 105

#include <vector>
#include <algorithm>

using std::max;
using std::vector;

class Solution {
public:
    // 任意一天状态结束后有如下几种状态
    // 1. 没有买入卖出记录
    // 2. 买入了一次，但没有卖出
    // 3. 买入了一次，卖出了一次
    // 4. 买入了一次，卖出了一次，再买入了一次
    // 5. 买入了一次，卖出了一次，再买入了一次，再卖出了一次
    // 对与第一种状态的最大收益为0，其余各种状态的最大收益可以用
    // buy_1, sell_1, buy_2, sell_2来表示每天结束后各种状态下的最大收益。
    // 则第i天各种状态下的最大收益可以通过第i-1天各状态下最大收益推导出来，
    // buy_1', sell_1', buy_2', sell_2'分别表示第i-1天结束后的最大收益，
    // 则有各个状态转移方程为：
    // buy_1 = max(buy_1', -prices[i]) 第i天结束后状态为买入一股时的最大收益
    // sell_1 = max(sell_1', buy_1'+prices[i]) 第i天结束后状态为卖出一股时的最大收益
    // buy_2 = max(buy_2', sell_1'-prices[i])  第i天结束后状态为买入第二次时的最大收益
    // sell_2 = max(sell_2', buy_2'+prices[i])  第i天结束后状态为卖入第二次时的最大收益
    // 无论题目中是否允许「在同一天买入并且卖出」这一操作，最终的答案都不会受到影响，
    // 这是因为这一操作带来的收益为零。

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy_1 = -prices[0], sell_1 = 0;
        int buy_2 = -prices[0], sell_2 = 0;
        for (int i = 1; i < n; i++) {
            buy_1 = max(buy_1, -prices[i]);
            sell_1 = max(sell_1, buy_1+prices[i]);
            buy_2 = max(buy_2, sell_1-prices[i]);
            sell_2 = max(sell_2, buy_2+prices[i]);
        }
        return sell_2;
    }
};
