// 题目：
// Find the kth largest element in an unsorted array.
// Note that it is the kth largest element in the sorted order,
// not the kth distinct element.
// For example, Given [3,2,1,5,6,4] and k = 2, return 5.
// Note: You may assume k is always valid, 1 ≤ k ≤ array's length.
// 思路：
// 借鉴快速排序的思想，可以在o(n)的时间复杂度，o(1)的空间复杂度内完成。


class Solution {

    public static void main(String[] args) {
        int[] nums = new int[]{9, 5, 6, 2, 3, 4, 1, 7, 8, 0};
        assert(findKthLargest(nums, 1) == 9);
        assert(findKthLargest(nums, 2) == 8);
        assert(findKthLargest(nums, 10) == 0);
    }

    public static int findKthLargest(int[] nums, int k) {
        k = nums.length - k;
        int low = 0, high = nums.length - 1;
        int p = partition(nums, low, high);
        while (p != k) {
            if (p < k) low = p + 1;
            else high = p - 1;
            p = partition(nums, low, high);
        }
        return nums[k];
    }

    public static int partition(int[] nums, int low, int high) {
        int pivot = nums[high];
        while (low < high) {
            while (low < high && nums[low] <= pivot) low++;
            nums[high] = nums[low];
            while (low < high && nums[high] >= pivot) high--;
            nums[low] = nums[high];
        }
        nums[low] = pivot;
        return low;
    }
}
