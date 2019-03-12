// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].


object Solution {
    def main(args: Array[String]) {
      val nums: Array[Int] = Array(2, 7, 11, 15)
      assert(twoSum(nums, 9)(0) == 0)
      assert(twoSum(nums, 18)(0) == 1)
      assert(twoSum(nums, 20) == null)
    }

    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
      nums.zipWithIndex.foldLeft(Map.empty[Int, Int])((m, x) => {
        if (m.get(target - x._1) == None)
          m+(x._1 -> x._2)
        else
          return Array(m.getOrElse(target-x._1, -1), x._2)
      })
      return null
    }
}
