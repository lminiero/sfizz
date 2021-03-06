// SPDX-License-Identifier: BSD-2-Clause

// This code is part of the sfizz library and is licensed under a BSD 2-clause
// license. You should have receive a LICENSE.md file along with the code.
// If not, contact the sfizz maintainers at https://github.com/sfztools/sfizz

#include "sfizz/Region.h"
#include "catch2/catch.hpp"
using namespace Catch::literals;

TEST_CASE("[Opcode] Construction")
{
    SECTION("Normal construction")
    {
        sfz::Opcode opcode { "sample", "dummy" };
        REQUIRE(opcode.opcode == "sample");
        REQUIRE(opcode.value == "dummy");
        REQUIRE(!opcode.parameter);
    }

    SECTION("Normal construction with underscore")
    {
        sfz::Opcode opcode { "sample_underscore", "dummy" };
        REQUIRE(opcode.opcode == "sample_underscore");
        REQUIRE(opcode.value == "dummy");
        REQUIRE(!opcode.parameter);
    }

    SECTION("Parameterized opcode")
    {
        sfz::Opcode opcode { "sample123", "dummy" };
        REQUIRE(opcode.opcode == "sample");
        REQUIRE(opcode.value == "dummy");
        REQUIRE(opcode.parameter);
        REQUIRE(*opcode.parameter == 123);
    }

    SECTION("Parameterized opcode with underscore")
    {
        sfz::Opcode opcode { "sample_underscore123", "dummy" };
        REQUIRE(opcode.opcode == "sample_underscore");
        REQUIRE(opcode.value == "dummy");
        REQUIRE(opcode.parameter);
        REQUIRE(*opcode.parameter == 123);
    }
}

TEST_CASE("[Opcode] Note values")
{
    auto noteValue = sfz::readNoteValue("c-1");
    REQUIRE(noteValue);
    REQUIRE(*noteValue == 0);
    noteValue = sfz::readNoteValue("C-1");
    REQUIRE(noteValue);
    REQUIRE(*noteValue == 0);
    noteValue = sfz::readNoteValue("g9");
    REQUIRE(noteValue);
    REQUIRE(*noteValue == 127);
    noteValue = sfz::readNoteValue("G9");
    REQUIRE(noteValue);
    REQUIRE(*noteValue == 127);
    noteValue = sfz::readNoteValue("c#4");
    REQUIRE(noteValue);
    REQUIRE(*noteValue == 61);
    noteValue = sfz::readNoteValue("C#4");
    REQUIRE(noteValue);
    REQUIRE(*noteValue == 61);
}
