// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

// Follow up:
// Could you solve it in linear time?

// Example:

// Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
// Output: [3,3,5,5,6,7] 
// Explanation: 

// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3  
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
#include<vector>
#include<deque>

using std::deque;
using std::vector;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.size() <= 0)
            return result;

        deque<int> window; // window里放的是下标
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k && window.front() <= i-k)
                window.pop_front();
            while (window.size() > 0 && nums[window.back()] <= nums[i])
                window.pop_back();
            window.push_back(i);
            if (i >= k - 1) 
                result.push_back(nums[window.front()]);
        }
        return result;
    }
};
