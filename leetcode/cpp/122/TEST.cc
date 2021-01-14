#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hh"
#include "solution.h"


TEST_CASE("122", "bestTimetoBuyandSellStock2")
{
    Solution s;
    {
        vector<int> prices_1 = {7, 1, 5, 3, 6, 4};
        REQUIRE( (s.maxProfit(prices_1) == 7) );

        vector<int> prices_2 = {1, 2, 3, 4, 5};
        REQUIRE( (s.maxProfit(prices_2) == 4) );

        vector<int> prices_3 = {7, 6, 4, 3, 1};
        REQUIRE( (s.maxProfit(prices_3) == 0) );
    }
}
