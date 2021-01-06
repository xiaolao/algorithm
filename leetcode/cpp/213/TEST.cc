#include <iostream>
#include <vector>
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hh"
#include "solution.h"


TEST_CASE("213", "houseRobber2")
{
    Solution s;
    {
        vector<int> nums = {2};
        REQUIRE( (s.rob(nums) == 2) );

        vector<int> nums1 = {2, 3};
        REQUIRE( (s.rob(nums1) == 3) );

        vector<int> nums3 = {2, 3, 2};
        REQUIRE( (s.rob(nums3) == 3) );

        vector<int> nums2 = {1, 2, 3, 1};
        REQUIRE( (s.rob(nums2) == 4) );

        vector<int> nums4 = {1, 1, 1, 2};
        std::clog << s.rob(nums4) << "\n";
        REQUIRE( (s.rob(nums4) == 3) );

        vector<int> nums5 = {1,1,3,6,7,10,7,1,8,5,9,1,4,4,3};
        std::clog << s.rob(nums5) << "\n";
        REQUIRE( (s.rob(nums5) == 41) );
    }


}
