// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//  An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.
import java.util.Stack;
import java.util.HashMap;

class Solution {

    public static void main(String[] args) throws Exception {
        assert isValid("()");
        assert isValid("(){}[]");
        assert !isValid("(]");
        assert !isValid("([)]");
        assert isValid("{[]}");
    }

    public static boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        HashMap<Character, Character> pairs = new HashMap<Character, Character>();
        pairs.put(')', '(');
        pairs.put('}', '{');
        pairs.put(']', '[');

        char[] chars = s.toCharArray();
        for (char c : chars) {
            if (!pairs.containsKey(c)) {
                stack.push(c);
            } else if (stack.isEmpty() || pairs.get(c) != stack.pop()) {
                return false;
            }
        }
        return stack.isEmpty();
    }
}
