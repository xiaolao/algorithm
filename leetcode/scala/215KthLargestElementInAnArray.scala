// 题目：
// Find the kth largest element in an unsorted array.
// Note that it is the kth largest element in the sorted order,
// not the kth distinct element.
// For example, Given [3,2,1,5,6,4] and k = 2, return 5.
// Note: You may assume k is always valid, 1 ≤ k ≤ array's length.
// 思路：
// 借鉴快速排序的思想，可以在o(n)的时间复杂度，o(1)的空间复杂度内完成。


object Solution {
  def main(args: Array[String]) {
    val nums: Array[Int] = Array(9, 5, 6, 2, 3, 4, 1, 7, 8, 0)
    assert(findKthLargest(nums, 1) == 9)
    println(nums.mkString)
    assert(findKthLargest(nums, 2) == 8)
    println(nums.mkString)
    assert(findKthLargest(nums, 10) == 0)
    println(nums.mkString)
  }

  def findKthLargest(nums: Array[Int], k: Int): Int = {
    val nk: Int = nums.length - k
    var start: Int = 0
    var end: Int = nums.length - 1
    var p: Int = partition(nums, start, end)
    while (p != nk) {
      if (p < nk) {
        start = p + 1
      } else {
        end = p - 1
      }
      p = partition(nums, start, end)
    }
    return nums(nk)
  }

  def partition(nums: Array[Int], start: Int, end: Int): Int = {
    var low = start
    var high = end
    val pivot: Int = nums(high)
    while (low < high) {
      while (low < high && nums(low) <= pivot) {
        low += 1
      }
      nums(high) = nums(low)
      while (low < high && nums(high) >= pivot) {
        high -= 1
      }
      nums(low) = nums(high)
    }
    nums(low) = pivot
    return low
  }
}
