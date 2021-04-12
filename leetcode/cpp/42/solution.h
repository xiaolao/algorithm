// 剑指 Offer 42. 连续子数组的最大和  LCOF

#include <vector>
#include <algorithm>

using std::max;
using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 定义状态dp[i]为包含nums[i]的最大连续子序和
        int n = nums.size();
        if (n == 0) return 0;
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            nums[i] += max(nums[i-1], 0);
            sum = max(sum, nums[i]);
        }
        return sum;
    }
};
