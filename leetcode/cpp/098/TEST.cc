#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hh"
#include "solution.h"
#include <vector>


TEST_CASE("098", "validateBinarySearchTree")
{

    Solution s;
    {
        TreeNode root = TreeNode(2);
        TreeNode node_1 = TreeNode(1);
        TreeNode node_2 = TreeNode(3);

        root.left = &node_1;
        root.right = &node_2;

        REQUIRE( s.isValidBST(&root) );

    }

    {
        TreeNode root = TreeNode(5);
        TreeNode node_1 = TreeNode(1);
        TreeNode node_2 = TreeNode(4);
        TreeNode node_5 = TreeNode(3);
        TreeNode node_6 = TreeNode(6);

        root.left = &node_1;
        root.right = &node_2;
        node_2.left = &node_5;
        node_2.right = &node_6;

        REQUIRE( !s.isValidBST(&root) );
    }

}
