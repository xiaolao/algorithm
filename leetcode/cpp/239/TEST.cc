#include <vector>
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hh"
#include "solution.h"

TEST_CASE("239", "[maxSlidingWindow]")
{
    Solution s;

    vector<int> nums1{1};
    REQUIRE( (s.maxSlidingWindow(nums1, 1) == vector<int>{1}) );

    vector<int> nums2{1, -1};
    REQUIRE( (s.maxSlidingWindow(nums2, 1) == vector<int>{1, -1}) );

    vector<int> nums3{9, 11};
    REQUIRE( (s.maxSlidingWindow(nums3, 2) == vector<int>{11}) );

    vector<int> nums4{4, -2};
    REQUIRE( (s.maxSlidingWindow(nums4, 2) == vector<int>{4}) );

    vector<int> nums5{1, 3, -1, -3, 5, 3, 6, 7};
    REQUIRE( (s.maxSlidingWindow(nums5, 3) == vector<int>{3, 3, 5, 5, 6, 7}) );
}
