// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
 

// Constraints:

// 1 <= n <= 45

class Solution {
public:

    /**
     * 动态规划：定义状态DP[i]为
     * 到第i个台阶有多少种走法，
     * 则有DP[i] = DP[i-1]+DP[i-2]
     */
     int climbStairs(int n) {
        if (n <= 2) return n;
        int dp_2 = 1, dp_1 = 2, res;
        for (int i = 0; i <= n; ++i) {
            res = dp_1 + dp_2;
            dp_2 = dp_1;
            dp_1 = res;
        }
        return res;
    }
};
