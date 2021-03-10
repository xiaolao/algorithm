// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

// It is guaranteed that the answer will fit in a 32-bit integer.

// A subarray is a contiguous subsequence of the array.

//  

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
//  

// Constraints:

// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10
#include <cmath>
#include <vector>
#include <algorithm>

using std::max;
using std::min;
using std::vector;

class Solution {
public:
    // 定义状态dp[i][0]为位置i最小连续乘积；dp[i][1]为最大连续乘积。
    // dp[i][0] = min(dp[i-1][0]*nums[i], nums[i], dp[i-1][1]*nums[i]);
    // dp[i][1] = max(dp[i0][0]*nums[i], nums[i], dp[i-1][1]*nums[i]);
    // 优化空间复杂度，使用maxF, minF, ans分别表示最大，最小乘积和结果。
    int maxProduct(vector<int>& nums) {
        int maxP = nums[0], minP = nums[0], ans = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            int maxT = maxP, minT = minP;
            maxP = max(nums[i], max(maxT*nums[i], minT*nums[i]));
            minP = min(nums[i], min(maxT*nums[i], minT*nums[i]));
            ans = max(ans, maxP);
        }
        return maxP;
    }
};
