//
// Created by snizzfox on 5/23/21.
//

//#include "dynamic_type.h"
#define CATCH_TEST_RUNNER

#include <catch2/catch.hpp>
#include "dynamic_type.h"

TEST_CASE("explicit zmb::dynamic_type::dynamic_type(numeric_type const & numericType)") {
    zmb::dynamic_type dt(34.0);
    REQUIRE(dt.check_type_is_num());
    REQUIRE(!dt.check_type_is_str());
}

TEST_CASE("explicit zmb::dynamic_type::dynamic_type(string_type const & stringType)") {
    zmb::dynamic_type dt("34");
    REQUIRE(!dt.check_type_is_num());
    REQUIRE(dt.check_type_is_str());

}

TEST_CASE("zmb::dynamic_type::set(numeric)", "dynamic_type") {
    static constexpr auto test_number{34.0};
    zmb::dynamic_type dt;
    dt.set(test_number);

    REQUIRE(dt.get_as_numeric() == test_number);

}

TEST_CASE("zmb::dynamic_type::set(string)", "dynamic_type") {
    static constexpr auto test_number{"34.0"};
    zmb::dynamic_type dt;
    dt.set(test_number);

    REQUIRE(dt.get_as_string() == test_number);

}


TEST_CASE("zmb::dynamic_type::check_type_is_num", "dynamic_type") {
    static constexpr auto test_value{34.0};

    zmb::dynamic_type dt;
    dt.set(test_value);
    REQUIRE(dt.check_type_is_num());
    REQUIRE(!dt.check_type_is_str());
}

TEST_CASE("zmb::dynamic_type::check_type_is_str", "dynamic_type") {
    static constexpr auto test_value{"34.0"};

    zmb::dynamic_type dt;
    dt.set(test_value);
    REQUIRE(!dt.check_type_is_num());
    REQUIRE(dt.check_type_is_str());
}

TEST_CASE("zmb::dynamic_type::get_as_string()", "dynamic_type") {
    zmb::dynamic_type dt("test");

    REQUIRE(dt.get_as_numeric() == 0.0);
    REQUIRE(dt.get_as_string() == "test");

}


TEST_CASE("zmb::dynamic_type::get_as_numeric()", "dynamic_type") {
    zmb::dynamic_type dt(100.0);

    REQUIRE(dt.get_as_numeric() == 100.0);
    REQUIRE(dt.get_as_string() == std::to_string(100.0));

}