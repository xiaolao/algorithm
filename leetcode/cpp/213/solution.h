// 213. House Robber II

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [0]
// Output: 0
//  

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000

// 可以将环状排列的房间问题化解为两个单排排列的房间问题
// 不偷窃第一个房子：nums[1:], 最大值金额为dp1
// 不偷窃最后一个房子：nums[:n-1]，最大金额为dp2
// 综合上面的情况取最大值：max(dp1, dp2)

#include <vector>
#include <utility>
#include <algorithm>

using std::max;
using std::pair;
using std::vector;


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;

        int size = nums.size();
        if (size == 1) return nums[0];

        int max_1 = rob(nums, 1, size);
        int max_2 = rob(nums, 0, size-1);

        return max(max_1, max_2);
    }

private:

    int rob(vector<int>& nums, int start, int end) {
        int prev = 0, curr = 0;
        for (int i = start; i < end; i++) {
            int tmp = curr;
            curr = max(prev+nums[i], curr);
            prev = tmp;
        }
        return curr;
    }
};
