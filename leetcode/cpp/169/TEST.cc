#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hh"
#include "solution.h"


TEST_CASE("169", "majorityElement")
{
    Solution s;
    {
        vector<int> nums = {3, 2, 3};
        REQUIRE( s.majorityElement(nums) == 3);
    }
    {
        vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
        REQUIRE( s.majorityElement(nums) == 2 );
    }

}
