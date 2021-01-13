// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

//  

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
//  

// Constraints:

// n == nums.length
// 1 <= n <= 5 * 104
// -231 <= nums[i] <= 231 - 1
//  

// Follow-up: Could you solve the problem in linear time and in O(1) space?

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> memory;
        for (auto key : nums) {
            auto find = memory.find(key);
            if (find == memory.end()) {
                memory[key] = 1;
            } else {
                memory[key]++;
            }
        }
        int majority, count = 0;
        for (auto item : memory) {
            if (item.second > count) {
                majority = item.first;
                count = item.second;
            }
        }
        return majority;
    }
};
