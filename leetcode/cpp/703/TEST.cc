#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hh"
#include "solution.h"

TEST_CASE("703", "[KthLargest]")
{
    {
        vector<int> nums{4, 5, 8, 2};
        KthLargest* obj = new KthLargest(4, nums);
        REQUIRE( (obj->add(3) == 4) );
        REQUIRE( (obj->add(5) == 5) );
        REQUIRE( (obj->add(10) == 5) );
        REQUIRE( (obj->add(9) == 8) );
        REQUIRE( (obj->add(4) == 8) );
    }

}
