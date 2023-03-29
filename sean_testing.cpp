#include <cstdlib>
#include <iostream>
#include <string>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "space.hpp"

TEST_CASE("array of positive ints")
{

	int a[] = {1,2,3,4,5,6,7};
	space::sout("a", a, 7);
	CHECK(space::data["a"]["data"] == "      [1, 2, 3, 4, 5, 6, 7],\n");
}

TEST_CASE("array of negative ints")
{
	int negative_array[] = {-1,-6,-8,-10,-3,5,29,40};
	space::sout("negative_array", negative_array, 8);
	CHECK(space::data["negative_array"]["data"] == "      [-1, -6, -8, -10, -3, 5, 29, 40],\n");	
}

TEST_CASE("array of single chars")
{
	char char_array0[] = {'g','f','e','d','c','b','a'};
	space::sout("char_array0", char_array0, 7);
	CHECK(space::data["char_array0"]["data"] == "      [103, 102, 101, 100, 99, 98, 97],\n");
}

TEST_CASE("array of single chars with indices")
{
	char char_array1[] = {'g','f','e','d','c','b','a'};
	space::sout("char_array1", char_array1, 7, 0, 1);
	CHECK(space::data["char_array1"]["data"] == "      [103, 102, 101, 100, 99, 98, 97],\n");
	CHECK(space::data["char_array1"]["indices"] == "      [0, 1],\n");
}

TEST_CASE("array of doubles")
{
	double double_array0[] = {7.5, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0};
	space::sout("double_array0", double_array0, 7);
	CHECK(space::data["double_array0"]["data"] == "      [7.5, 6, 5, 4, 3, 2, 1],\n");
}
