#include <cstdlib>
#include <iostream>
#include <string>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "space.hpp"

//6 spaces in the "" that comes before the ==
//',\n' after the array
//space after each comma for testing array


TEST_CASE("testing array of positive ints"){
	int a[] = {1,2,3,4,5,6,7};
	space::sout("a", a, 7);
	CHECK(space::data["a"]["data"] == "      [1, 2, 3, 4, 5, 6, 7],\n");
}

TEST_CASE("testing array of positive doubles with indices"){
	double ind_A[] = {7.5,6.0,5.0,4.0,3.0,2.0,1.0};
	space::sout("ind_A", ind_A, 7,0,1);
	CHECK(space::data["ind_A"]["data"] == "      [7.5, 6, 5, 4, 3, 2, 1],\n");
	CHECK(space::data["ind_A"]["indices"] == "      [0, 1],\n");
	}

	/*TEST_CASE("testing string array"){
		char str_A[] = {"Sazzad" "Sean" "Chris" "Michael"};
		space::sout("str_A", str_A, 1);
		CHECK(space::data["str_A"]["data"] == "      [Sazzad, Sean, Chris, Michael],\n");
	}*/

TEST_CASE("testing array of positive ints and indices"){
	int aind_array[] = {1,2,3,4,5,6,7};
	space::sout("aind_array", aind_array, 7,0,1);
	CHECK(space::data["aind_array"]["data"] == "      [1, 2, 3, 4, 5, 6, 7],\n");
	CHECK(space::data["aind_array"]["indices"] == "      [0, 1],\n");
}

TEST_CASE("testing a boolean array"){
	bool b_array[] = {true,true,false,true,false};
	space::sout("b_array", b_array, 5);
	CHECK(space::data["b_array"]["data"] == "      [1, 1, 0, 1, 0],\n");
}

TEST_CASE("testing a boolean array with indices"){
	bool bind_array[] = {true,true,false,true,false};
	space::sout("bind_array", bind_array, 5,0,1);
	CHECK(space::data["bind_array"]["data"] == "      [1, 1, 0, 1, 0],\n");
	CHECK(space::data["bind_array"]["indices"] == "      [0, 1],\n");
}
