// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

import java.util.Map;
import java.util.HashMap;

class Solution {

    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        int[] ret = new int[2];
        for(int i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i])) {
                ret[0] = map.get(target - nums[i]);
                ret[1] = i;
            }
            map.put(nums[i], i);
        }
        return ret;
    }

    public static void main(String[] args) throws Exception {
        int[] nums = new int[]{2, 7, 11, 15};
        assert twoSum(nums, 9)[0] == 0;
        assert twoSum(nums, 18)[0] == 1;
        assert twoSum(nums, 20) == null;
    }
}
