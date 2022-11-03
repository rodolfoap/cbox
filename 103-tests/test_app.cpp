#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "reverse.hpp"

TEST_CASE("Testing framework is working fine", "[Catch2]"){
	REQUIRE(true);
}

TEST_CASE("Testing simple REQUIRE", "[reverse]"){
	int year = 1920;
	REQUIRE(year == 1920);
}

TEST_CASE("Testing arithmetics", "[reverse]"){
	int year = 1640;
	REQUIRE(year+1 == 1641);
}

TEST_CASE("Short-word match testing", "[reverse]"){
	char n[5]="abcd", r[5]={};
	reverse(n, r);
	REQUIRE_THAT(r, Catch::Matchers::Matches("dcba"));
}

TEST_CASE("Long-word match testing", "[reverse]"){
	char n[101]="happen upon truth by a trick of the eye, if the truth falsehood of the resulting belief is important";
	char r[101]={};
	reverse(n, r);
	REQUIRE_THAT(r, Catch::Matchers::Matches("tnatropmi si feileb gnitluser eht fo dooheslaf hturt eht fi ,eye eht fo kcirt a yb hturt nopu neppah"));
}

TEST_CASE("Numbers match testing", "[reverse]"){
	char n[5]="9174", r[5]={};
	reverse(n, r);
	REQUIRE_THAT(r, Catch::Matchers::Matches("4719"));
}

TEST_CASE("ASCII match testing", "[reverse]"){
	char n[5]="#&@!", r[5]={};
	reverse(n, r);
	REQUIRE_THAT(r, Catch::Matchers::Matches("!@&#"));
}
