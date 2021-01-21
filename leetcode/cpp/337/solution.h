// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Determine the maximum amount of money the thief can rob tonight without alerting the police.

// Example 1:

// Input: [3,2,3,null,3,null,1]

//      3
//     / \
//    2   3
//     \   \/ 
//      3   1

// Output: 7 
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:

// Input: [3,4,5,1,3,null,1]

//      3
//     / \
//    4   5
//   / \   \/ 
//  1   3   1

// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// 方法一: 暴力递归-最优子结构
// 四个孙子节点与爷爷节点的钱 VS 两个父节点的钱
// int m1 = root.val + rob(root.left.left) + rob(root.left.right) + rob(root.right.left) + rob(root.right.right)
// int m2 = rob(root.left) + rob(root.right)
// result: max(m1, m2)


// 方法二: 记忆化 - 解决重复子问题
// 使用字典存储节点i为根节点时，能偷取的最大


// 方法三: 记忆化 - 解决重复子问题
// 对于节点o有两种状态，偷取o或者不偷窃o，
// 记f(o)为偷窃o时，以o为根节点子树能偷窃的最大金额
// 记g(o)为不偷窃o，以o为根节点子树能偷窃的最大金额
// f(o) = g(l) + g(r)
// g(o) = max(f(l), g(l)) + max(f(r), g(r))
// result = max(f(o), g(o))


// pre-order  root, left,  right
// in-order   left, root,  right 
// post-order left, right, root


#include <algorithm>
#include <unordered_map>

using std::max;
using std::unordered_map;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


struct SubTreeStatus {
    int robed;
    int notrobed;
};


class Solution {

public:

    // 动态规划
    int rob(TreeNode* root) {
        SubTreeStatus root_status = dfs(root);
        return max(root_status.robed, root_status.notrobed);
    }

    SubTreeStatus dfs(TreeNode* root) {
        if (root == nullptr) return {0, 0};

        SubTreeStatus left_sub_tree = dfs(root->left);
        SubTreeStatus right_sub_tree = dfs(root->right);

        int robed = root->val + left_sub_tree.notrobed + right_sub_tree.notrobed;
        int notrobed = max(left_sub_tree.robed, left_sub_tree.notrobed) + max(
                right_sub_tree.robed, right_sub_tree.notrobed);

        return {robed, notrobed};
    }

    // 暴力递归-最优子结构
    int rob1(TreeNode* root) {
        if (root == nullptr) return 0;

        int grand_money = root->val;
        if (root->left != nullptr) {
            grand_money += rob1(root->left->left) + rob1(root->left->right);
        }

        if (root->right != nullptr) {
            grand_money += rob1(root->right->left) + rob1(root->right->right);
        }

        int parent_money = rob1(root->left) + rob1(root->right);

        return max(grand_money, parent_money);
    }

    // 记忆化-解决重复子问题
    int rob2(TreeNode* root) {
        if (root == nullptr) return 0;

        // 使用hash table存储各个节点为root是能偷取的最大金额
        auto find = memory.find(root);
        if (find != memory.end()) return find->second;

        int grand_money = root->val;
        if (root->left != nullptr) {
            grand_money += rob2(root->left->left) + rob2(root->left->right);
        }

        if (root->right != nullptr) {
            grand_money += rob2(root->right->left) + rob2(root->right->right);
        }

        int parent_money = rob2(root->left) + rob2(root->right);

        int result = max(parent_money, grand_money);
        memory[root] = result;

        return result;
    }

private:
    unordered_map<TreeNode*, int> memory;
};
