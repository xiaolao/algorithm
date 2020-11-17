#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hh"
#include "solution.h"


TEST_CASE("242", "Valid Anagram")
{
    Solution s;

    REQUIRE( s.isAnagram("anagram", "nagaram") );
    REQUIRE( s.isAnagram2("anagram", "nagaram") );
    REQUIRE( s.isAnagram3("anagram", "nagaram") );
}
