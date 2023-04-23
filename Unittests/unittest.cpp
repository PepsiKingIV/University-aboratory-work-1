#define DOCTEST_CONFIG_NO_MULTITHREADING
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "histogram_internal.h"

TEST_CASE("distinct positive numbers") {
    double min = 0;
    double max = 0;
    find_minmax({1, 2}, min, max);
    CHECK(min == 1);
    CHECK(max == 2);
}