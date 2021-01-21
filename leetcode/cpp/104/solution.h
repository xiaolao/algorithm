// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: 3
// Example 2:

// Input: root = [1,null,2]
// Output: 2
// Example 3:

// Input: root = []
// Output: 0
// Example 4:

// Input: root = [0]
// Output: 1
//  

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -100 <= Node.val <= 100

#include <algorithm>

using std::max;
using std::min;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==nullptr) return 0;
        int left_depth = dfs(root->left, 1);
        int right_depth = dfs(root->right, 1);
        return left_depth > right_depth ? left_depth : right_depth;
    }

    // 与102的深度优先搜索解法类似
    int dfs(TreeNode* node, int level) {
        if (node==nullptr) return level;
        int left_depth = dfs(node->left, level + 1);
        int right_depth = dfs(node->right, level+1);
        return left_depth > right_depth ? left_depth : right_depth;
    }

    int maxDepthII(TreeNode* root) {
        return root==nullptr ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    int minDepth(TreeNode* root) {
        if (root==nullptr) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return (left==0 || right==0) ? 
            left+right+1 : 1+min(left, right);
    }
};
