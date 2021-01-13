#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hh"
#include "solution.h"


TEST_CASE("050", "pow")
{
    Solution s;
    {
        double x = 2.0;
        int n = 10;
        double result(1024.0);
        REQUIRE( s.myPow(x, n) == result );
    }
    {
        double x = 0.0;
        int n = 3;
        REQUIRE( s.myPow(x, n) == 0.0 );
    }
    {
        double x = 2;
        int n = -2;
        REQUIRE( (s.myPow(x, n) == 0.25) );
    }
    {
        double x = 3;
        int n = 0;
        REQUIRE( (s.myPow(x, n) == 1.0) );
    }

}
