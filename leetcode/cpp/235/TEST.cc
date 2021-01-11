#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hh"
#include "solution.h"
#include <vector>


TEST_CASE("235", "lowestCommonAncestorofaBinarySearchTree")
{

    Solution s;
    {
        TreeNode root = TreeNode(6);
        TreeNode node_1 = TreeNode(2);
        TreeNode node_2 = TreeNode(8);
        TreeNode node_3 = TreeNode(0);
        TreeNode node_4 = TreeNode(4);
        TreeNode node_5 = TreeNode(7);
        TreeNode node_6 = TreeNode(9);
        TreeNode node_9 = TreeNode(3);
        TreeNode node_10 = TreeNode(5);

        root.left = &node_1;
        root.right = &node_2;
        node_1.left = &node_3;
        node_1.right = &node_4;
        node_2.left = &node_5;
        node_2.right = &node_6;
        node_4.left = &node_9;
        node_4.right = &node_10;

        REQUIRE( s.lowestCommonAncestor(&root, &node_1, &node_2) == &root );
        REQUIRE( s.lowestCommonAncestor(&root, &node_1, &node_4) == &node_1 );

    }

}
