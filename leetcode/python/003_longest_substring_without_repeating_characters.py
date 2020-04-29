# Given a string, find the length of the longest substring without repeating characters.

# Example 1:

# Input: "abcabcbb"
# Output: 3 
# Explanation: The answer is "abc", with the length of 3. 
# Example 2:

# Input: "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.
# Example 3:

# Input: "pwwkew"
# Output: 3
# Explanation: The answer is "wke", with the length of 3. 
#              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution:

    def lengthOfLongestSubstring(self, s: str) -> int:
        pass

    # 方法一暴力求解
    def lengthOfLongestSubstring_1(self, s: str) -> int:
        if not s: return 0
        m = 0
        for i in range(0, len(s)):
            for j in range(i+1, len(s)+1):
                if len(set(s[i:j])) == j-i:
                    m = max(m, j-i)
        return m

    # 滑动窗口
    def lengthOfLongestSubstring_2(self, s: str) -> int:
        pass

    # 优化滑动窗口
    def lengthOfLongestSubstring_3(self, s: str) -> int:
        pass


if __name__ == "__main__":
    a = "abcabcbb"
    b = "bbbbb"
    c = "pwwkew"
    d = " "
    e = "e"
    solution = Solution()

    # 暴力求解
    assert solution.lengthOfLongestSubstring_1(a) == 3
    assert solution.lengthOfLongestSubstring_1(b) == 1
    assert solution.lengthOfLongestSubstring_1(c) == 3
    assert solution.lengthOfLongestSubstring_1(d) == 1
    assert solution.lengthOfLongestSubstring_1(e) == 1

