#include <vector>
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hh"
#include "solution.h"


TEST_CASE("015", "threeSum")
{
    Solution s;
    {
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> result = {{-1, -1, 2},{-1, 0, 1}};
        REQUIRE( (s.threeSum(nums) == result) );

        vector<int> nums2;
        vector<vector<int>> result2;
        REQUIRE( (s.threeSum(nums2) == result2) );

        vector<int> nums3 = {0};
        REQUIRE( (s.threeSum(nums3) == result2) );

        vector<int> nums4 = {0, 0, 0, 0, 0, 0};
        vector<vector<int>> result4 = {{0, 0, 0},};
        REQUIRE( (s.threeSum(nums4) == result4) );
    }

    {
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> result = {{-1, -1, 2},{-1, 0, 1}};
        REQUIRE( (s.threeSum2(nums) == result) );

        vector<int> nums2;
        vector<vector<int>> result2;
        REQUIRE( (s.threeSum2(nums2) == result2) );

        vector<int> nums3 = {0};
        REQUIRE( (s.threeSum2(nums3) == result2) );

        vector<int> nums4 = {0, 0, 0, 0, 0, 0};
        vector<vector<int>> result4 = {{0, 0, 0},};
        REQUIRE( (s.threeSum(nums4) == result4) );
    }

    {
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> result = {{-1, -1, 2},{-1, 0, 1}};
        REQUIRE( (s.threeSum3(nums) == result) );

        vector<int> nums2;
        vector<vector<int>> result2;
        REQUIRE( (s.threeSum3(nums2) == result2) );

        vector<int> nums3 = {0};
        REQUIRE( (s.threeSum3(nums3) == result2) );

        vector<int> nums4 = {0, 0, 0, 0, 0, 0};
        vector<vector<int>> result4 = {{0, 0, 0},};
        REQUIRE( (s.threeSum(nums4) == result4) );
    }

}
