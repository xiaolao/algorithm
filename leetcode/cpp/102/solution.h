// 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

//  

// 示例：
// 二叉树：[3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回其层序遍历结果：

// [
//   [3],
//   [9,20],
//   [15,7]
// ]

#include <sys/_types/_size_t.h>
#include <vector>
#include <queue>

using std::vector;
using std::queue;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    // BFS + 内嵌套循环
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            size_t level_size = q.size();
            vector<int> level_value;
            for (size_t i = 0; i < level_size; i++) {
                TreeNode* node = q.front(); 
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                level_value.push_back(node->val);
                q.pop();
            }
            result.push_back(level_value);
        }

        return result;
    }

    // DFS
    vector<vector<int>> levelOrderII(TreeNode* root) {
        result.clear();
        if (root==nullptr) return result;
        dfs(root, 0);
        return result;
    }

    void dfs(TreeNode* node, int level) {
        if (node==nullptr) return;

        if (result.size() < level + 1) {
            result.push_back({});
        }
        result[level].push_back(node->val);
        dfs(node->left, level + 1);
        dfs(node->left, level + 1);
    }

private:
    vector<vector<int>> result;
};
