// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
#include<vector>
#include<unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> record;
        for(int i = 0; i < nums.size(); ++i) {
            auto find = record.find(nums[i]);
            if(find != record.end())
                return {find->second, i};
            record.emplace(target-nums[i], i);
        }
        return {-1, -1};
    }
};
