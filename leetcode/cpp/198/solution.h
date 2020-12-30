// 198. House Robber

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.


// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
//              Total amount you can rob = 2 + 9 + 1 = 12.

// Constraints:

// 0 <= nums.length <= 100
// 0 <= nums[i] <= 400

// 动态规划 nums为输入数组
// dp[i]: 表示遍历到第i个位置时偷到的最大金额
// dp[i] = max(dp[i-1], dp[i-2]+nums[i])



#include <vector>
#include <algorithm>

using std::max;
using std::vector;


class Solution {
public:
    // 动态规划+使用vector保存状态
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;

        int size = nums.size();
        if (size == 1) return nums[0];

        vector<int> dp = vector<int>(size, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }

        return dp[size-1];
    }

    // 动态规划+使用滚动数组
    int rob2(vector<int> nums) {
        if (nums.empty()) return 0;

        int size = nums.size();
        if (size == 1) return nums[0];

        int dpi_2 = nums[0], dpi_1 = max(nums[0], nums[1]);

        for (int i = 2; i < size; i++) {
            int tmp = dpi_1;
            dpi_1 = max(dpi_1, dpi_2 + nums[i]);
            dpi_2 = tmp;
        }
        return dpi_1;
    }
};
