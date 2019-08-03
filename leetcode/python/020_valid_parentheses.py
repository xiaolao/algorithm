# Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

# An input string is valid if:

# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.
# Note that an empty string is also considered valid.


class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        peren_map = {")": "(", "]": "[", "}": "{"}
        for c in s:
            if c not in peren_map:
                stack.append(c)
            elif not stack or peren_map[c] != stack.pop():
                return False
        return not stack


if __name__ == "__main__":
    solution = Solution()
    assert solution.isValid("()") is True
    assert solution.isValid("(){}[]") is True
    assert solution.isValid("(]") is False
    assert solution.isValid("([)]") is False
    assert solution.isValid("{[]}") is True

