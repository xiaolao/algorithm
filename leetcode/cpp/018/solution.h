// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Notice that the solution set must not contain duplicate quadruplets.

//  

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [], target = 0
// Output: []
//  

// Constraints:

// 0 <= nums.length <= 200
// -10^9 <= nums[i] <= 10^9
// -10^9 <= target <= 10^9

#include<vector>
#include<algorithm>

using std::sort;
using std::vector;


class Solution {
public:
    // 排序+双指针解法
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int nums_size = nums.size();
        vector<vector<int>> result;
        if (nums_size < 4) return result;

        sort(nums.begin(), nums.end());

        for (int first = 0; first < nums_size - 3; first++) {
            if (first > 0 && nums[first] == nums[first-1]) continue; // 去重
            if (nums[first] + nums[first+1] + nums[first+2] + nums[first+3] > target) break; // 前四个数值之和大于target则无解
            if (nums[first] + nums[nums_size-3] + nums[nums_size-2] + nums[nums_size-1] < target) continue;

            for (int second = first + 1; second < nums_size - 2; second++) {
                if (second > first + 1 && nums[second] == nums[second-1]) continue;
                if (nums[first] + nums[second] + nums[second+1] + nums[second+2] > target) break; // 若前两个数已经大于target，则无解
                if (nums[first] + nums[second] + nums[nums_size-2] + nums[nums_size-1] < target) continue;

                int left = second + 1, right = nums_size - 1, mark = target - nums[first] - nums[second];

                while (left < right) {
                    if (nums[left] + nums[right] == mark) {
                        result.push_back({nums[first], nums[second], nums[left], nums[right]});

                        left++, right--;
                        while (left < right && nums[left] == nums[left-1]) left++;
                        while (left < right && nums[right] == nums[right+1]) right--;
                        
                    } else if (nums[left] + nums[right] < mark) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};
