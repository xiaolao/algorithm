// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Example 1: 
//
//    2
//   / \/
//  1   3
//
// Input: root = [2,1,3]
// Output: true
//
// Example 2: 
//
//       5
//      / \/
//     1   4
//        / \/
//       3   6
//
// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.
//
// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// -231 <= Node.val <= 231 - 1


//
// 思路一：使用中序遍历整个二叉树，得到的array是升序的
// 

#include <cmath>
#include <vector>

using std::vector;


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
    bool inOrderValid(TreeNode* root) {
        if (root == nullptr) return true;

        if(!inOrderValid(root->left))  return false;
        if (prev != nullptr && prev->val > root->val) return false;

        prev = root;
        return inOrderValid(root->right);
    }

    bool isValidBST(TreeNode* root) {
        prev = nullptr;
        return inOrderValid(root);
    }

private:
    TreeNode* prev;
};
