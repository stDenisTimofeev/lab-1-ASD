#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "generator.h"
#include "recurse.h"

TEST_CASE("Check iterative generator correctness", "[generator]") {
	Generator g(4, 3);
	std::vector<std::vector<bool> > tests = {
		{false, true, true, true},
		{true, false, true, true},
		{true, true, false, true},
		{true, true, true, false},
	};
	g.GenerateAll();
	REQUIRE(tests == g.Return());
}

TEST_CASE("Check recursive generator correctness", "[recurse]") {
	Recurse a(4, 3, 3);
	vector<int> q;
	std::vector<std::vector<int> > tests = {
		{0, 1, 1, 1},
		{1, 0, 1, 1},
		{1, 1, 0, 1},
		{1, 1, 1, 0},
	};
	a.GenerateAll(q);
	REQUIRE(tests == a.Return());
}