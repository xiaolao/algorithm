package main

type void struct{}

var null void

func lengthOfLongestSubstring(s string) int {
	return len(s)
}

// 方法一： 暴力求解，时间复杂度为O(n^3)
func lengthoflongestsubstring1(s string) int {
	length := len(s)
	if length == 0 {
		return 0
	}
	maxLength := 0
	for i := 0; i < length; i++ {
		for j := i + 1; j <= length; j++ {
			if isUniqueString(s[i:j]) && maxLength < j-i {
				maxLength = j - i
			}
		}
	}
	return maxLength
}

func isUniqueString(s string) bool {
	set := make(map[string]void)
	for _, i := range s {
		key := string(i)
		if _, exists := set[key]; exists {
			return false
		}
		set[key] = null
	}
	return true
}
