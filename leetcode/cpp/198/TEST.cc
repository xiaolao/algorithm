#include <vector>
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hh"
#include "solution.h"


TEST_CASE("198", "houseRobber1")
{
    Solution s;
    {
        vector<int> nums = {2};
        REQUIRE( (s.rob(nums) == 2) );

        vector<int> nums2 = {1, 2, 3, 1};
        
        REQUIRE( (s.rob(nums2) == 4) );

        vector<int> nums3 = {2, 7, 9, 3, 1};
        REQUIRE( (s.rob(nums3) == 12) );
    }

    {
        vector<int> nums = {2};
        REQUIRE( (s.rob2(nums) == 2) );

        vector<int> nums2 = {1, 2, 3, 1};
        REQUIRE( (s.rob2(nums2) == 4) );

        vector<int> nums3 = {2, 7, 9, 3, 1};
        REQUIRE( (s.rob2(nums3) == 12) );
    }

}
