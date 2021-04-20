// Given a binary tree, write a function to get the maximum width of the given tree. The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

// It is guaranteed that the answer will in the range of 32-bit signed integer.

// Example 1:

// Input: 

//            1
//          /   \
//         3     2
//        / \     \/
//       5   3     9 

// Output: 4
// Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
// Example 2:

// Input: 

//           1
//          /  
//         3    
//        / \/       
//       5   3     

// Output: 2
// Explanation: The maximum width existing in the third level with the length 2 (5,3).
// Example 3:

// Input: 

//           1
//          / \
//         3   2 
//        /        
//       5      

// Output: 2
// Explanation: The maximum width existing in the second level with the length 2 (3,2).
// Example 4:

// Input: 

//           1
//          / \
//         3   2
//        /     \/  
//       5       9 
//      /         \
//     6           7
// Output: 8
// Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
 
// Constraints:

// The given binary tree will have between 1 and 3000 nodes.

#include <algorithm>
#include <functional>
#include <unordered_map>

using std::max;
using std::function;
using std::unordered_map;

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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        unordered_map<uint64_t, uint64_t> left;

        uint64_t result = 1;
        function<void(TreeNode*, uint64_t, uint64_t)> dfs = [&](
                TreeNode* node, uint64_t depth, uint64_t pos) {

            if (node == nullptr) return;
            auto find = left.find(depth);
            if (find != left.end()) {
                result = max(result, pos - find->second + 1);
            } else {
                left[depth] = pos;
            }
            dfs(node->left, depth+1, pos*2);
            dfs(node->right, depth+1, pos*2+1);
        };

        dfs(root, 1, 1);
        return result;
    }
};
