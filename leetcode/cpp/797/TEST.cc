#include <vector>
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hh"
#include "solution.h"

TEST_CASE("797", "[allpathssourcetarget]")
{
    Solution s;

    {
        vector<vector<int>> edges = {{1, 0}, {2, 0}, {3, 2}, {3, 1}};
        vector<vector<int>> results = {{0, 1, 3}, {0, 2, 3}};
        REQUIRE( (s.allPathsSourceTarget(edges) == results) );
    }

    {
        vector<vector<int>> edges = {{1, 0}, {3, 0}, {4, 0}, {2, 1}, 
            {3, 1}, {4, 1}, {3, 2}, {4, 3}};
        vector<vector<int>> results = {{0,4},{0,3,4},{0,1,3,4},{0,1,2,3,4},{0,1,4}};
        REQUIRE( (s.allpathssourcetarget(edges) == results) );
    }
}
