// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

//  

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
//  

// Constraints:

// 1 <= n <= 8

#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    // 深度优先搜索与剪枝
    vector<string> generateParenthesis(int n) {
        size = n;
        result.clear();
        helper("", 0, 0);
        return result;
    }

    void helper(string vp, int left, int right) {
        if (left == size && right == size) {
            result.push_back(vp);
            return;
        }
        if (left < size) {
            helper(vp+"(", left+1, right);
        }

        if (right < size && right < left) {
            helper(vp+")", left, right+1);
        }
    }

private:
    int size;
    vector<string> result;
};
