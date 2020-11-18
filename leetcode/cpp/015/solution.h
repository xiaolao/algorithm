// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Example 2:

// Input: nums = []
// Output: []
// Example 3:

// Input: nums = [0]
// Output: []
 

// Constraints:

// 0 <= nums.length <= 3000
// -10^5 <= nums[i] <= 10^5
#include <set>
#include <vector>
#include <algorithm>


using std::sort;
using std::vector;


class Solution {
public:

    // 排序+双指针
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;

        sort(nums.begin(),  nums.end()); // 使用排序的办法去重

        for (int index = 0; index < nums.size()-2; index++) {
            if (nums[index] > 0) break; // 如果第一个数大于0，由于后面两个数一定大于0，故不可能有解

            // 当first遇到重复的值不必在找另外两个数，防止重复
            if (index > 0 && nums[index] == nums[index-1]) continue;

            int left = index + 1, right = nums.size() - 1, target = -nums[index];

            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    result.push_back({nums[index], nums[left], nums[right]});

                    left++, right--;
                    while (left < right && nums[left] == nums[left-1]) left++;
                    while (left < right && nums[right] == nums[right+1]) right--;
                } else if (nums[left] + nums[right] > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }

        return result;
    }

    // 暴力求解
    vector<vector<int>> threeSum2(vector<int>& nums) {
        sort(nums.begin(),  nums.end()); // 使用排序的办法去重

        vector<vector<int>> result;
        for (int first = 0; first < nums.size(); first++) {
            // 当first遇到重复的值不必在找另外两个数，防止重复
            if (first > 0 && nums[first] == nums[first-1]) continue;

            for (int second = first + 1; second < nums.size(); second++) {
                if (second > first + 1 && nums[second] == nums[second-1]) continue;

                for (int third = second + 1; third < nums.size(); third++) {
                    if (third > second + 1 && nums[third] == nums[third-1]) continue;

                    if (nums[first]+nums[second]+nums[third] == 0)
                        result.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }

        return result;
    }

};
