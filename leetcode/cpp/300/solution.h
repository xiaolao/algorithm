// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

//  

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
//  

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104
//  

// Follow up:

// Could you come up with the O(n2) solution?
// Could you improve it to O(n log(n)) time complexity?

#include <cstdio>
#include <vector>
#include <algorithm>

using std::max;
using std::vector;
using std::max_element;
using std::lower_bound;


class Solution {
public:
    // 方法一：动态规划法
    // 定义状态dp[i]为选中第i个数字时，位置
    // 0到i的最长上升子序的长度。则dp方程为
    // dp[i] = max(dp[j])+1,其中j属于[0, i)
    // 且nums[j] < nums[i];估结果为max(dp[i])。
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        for (size_t i = 0; i < n; ++i) {
            dp[i] = 1;
            for (size_t j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    // 方法二：数组 + 二分法
    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int *lis = new int[n+1];
        int len = 1;
        lis[len] = nums[0];

        for (size_t i = 1; i < n; ++i) {
            if (lis[len] < nums[i]) {
                lis[++len] = nums[i];
            } else {
                int l = 0, r = len, pos = 0;
                while (l <= r) {
                    int mid = (l+r)>>1;
                    if (lis[mid] < nums[i]) {
                        l = mid + 1;
                        pos = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                lis[pos+1] = nums[i];
            }
        }
        return len;
    }

    // 方法二：数组 + 二分法 + CPP语法特性
    int lengthOfLIS3(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> lis = {nums[0]};
        for (size_t i = 1; i < n; ++i) {
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
            if (it == lis.end())
                lis.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return lis.size();
    }
};
