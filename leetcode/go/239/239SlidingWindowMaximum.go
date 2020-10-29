package main

/* exmaple

@ -> left side; ^ -> right side

k = 3
        ^
loop 1 [1, 3, -1, -3, 5, 3, 6, 7]
        @

           ^
loop 2 [1, 3, -1, -3, 5, 3, 6, 7]
           @

               ^
loop 3 [1, 3, -1, -3, 5, 3, 6, 7] -> 3
           @

                   ^
loop 4 [1, 3, -1, -3, 5, 3, 6, 7] -> 3
           @

                      ^
loop 5 [1, 3, -1, -3, 5, 3, 6, 7] -> 5
               @ ...  @

                         ^
loop 6 [1, 3, -1, -3, 5, 3, 6, 7] -> 5
                      @

                            ^
loop 7 [1, 3, -1, -3, 5, 3, 6, 7] -> 6
                      @ ... @

                               ^
loop 8 [1, 3, -1, -3, 5, 3, 6, 7] -> 7
                               @

k = 2
        ^
loop 1 [7, 2, 4]
        @

           ^
loop 2 [7, 2, 4] -> 7
        @

              ^
loop 3 [7, 2, 4] -> 7
           @

*/

import "container/list"

// 定义window为容量是k的窗口，并且具有大顶堆的功能
// 即window[0] = max(window[:]),每轮遍历都要保证
// window[0]为该窗口中的最大元素。window表示可以使
// 用边界来表示,令left为指向window的左边的元素在
// 数组nums的下标,right为windows最右边的元素在数组
// nums的下标。
func maxSlidingWindow(nums []int, k int) []int {
	var result []int
	if len(nums) <= 0 {
		return result
	}

	window := list.New()
	for index, value := range nums {
		if index >= k && window.Front().Value.(int) <= index-k {
			window.Remove(window.Front())
		}

		for window.Len() > 0 && nums[window.Back().Value.(int)] <= value {
			window.Remove(window.Back())
		}

		window.PushBack(index)
		if index >= k-1 {
			result = append(result, nums[window.Front().Value.(int)])
		}

	}
	return result
}
