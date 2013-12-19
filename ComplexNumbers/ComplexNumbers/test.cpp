#define CATCH_CONFIG_MAIN
#include "include/catch.hpp"

#include "Complex.h"

TEST_CASE("Proper Construction of Objects", "Constructors")
{
	Complex def;
	Complex one_init(1.5);
	Complex two_init(2.5, -3.5);

	REQUIRE(def.Real() == 0 && def.Img() == 0);
	REQUIRE(one_init.Real() == 1.5 && one_init.Img() == 0);
	REQUIRE(two_init.Real() == 2.5 && two_init.Img() == -3.5);
}