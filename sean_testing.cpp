#include <cstdlib>
#include <iostream>
#include <string>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "space.hpp"

TEST_CASE("testing array of positive ints")
{
	int a[] = {1,2,3,4,5,6,7};
	space::sout("a", a, 7);
	CHECK(space::data["a"]["data"] == "      [1, 2, 3, 4, 5, 6, 7],\n");
}
