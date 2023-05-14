#include "studentas.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Teisingai ivestas vardas")
{
    Studentas s("Antanas", "Pavardenis", 7, 8);
    REQUIRE(s.vardas() == "Antanas");
}

TEST_CASE("Teisingai ivesta pavarde")
{
    Studentas s("Antanas", "Pavardenis", 7, 8);
    REQUIRE(s.pavarde() == "Pavardenis");
}

TEST_CASE("Teisingai ivestas vidurkis")
{
    Studentas s("Antanas", "Pavardenis", 7, 8);
    REQUIRE(s.vidurkis() == 7);
}

TEST_CASE("Teisingai ivesta mediana")
{
    Studentas s("Antanas", "Pavardenis", 7, 8);
    REQUIRE(s.mediana() == 8);
}
