// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//  An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.

package main

func isValid(s string) bool {
	stack := []rune{}
	perenMap := map[rune]rune{
		')': '(',
		'}': '{',
		']': '[',
	}
	for _, c := range s {
		if _, ok := perenMap[c]; !ok {
			stack = append(stack, c)
			continue
		}
		if len(stack) == 0 {
			return false
		}
		if perenMap[c] != stack[len(stack)-1] {
			return false
		}
		stack = stack[:len(stack)-1]
	}
	return len(stack) == 0
}
