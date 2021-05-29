//
// Created by snizzfox on 5/23/21.
//

#define CATCH_TEST_RUNNER
#include <functional>
#include <catch2/catch.hpp>
#include "task.h"


TEST_CASE("zmb::task::add_statement", "default"){
    zmb::task task;
    REQUIRE(task.size() == 0);
    task.add_statement(zmb::task_statement_enum::test);
    REQUIRE(task.size() == 1);
}

TEST_CASE("zmb::task::get_current_address", "default"){
    zmb::task task{};
    constexpr static auto address_test {0};

    REQUIRE(task.get_current_address() == zmb::task::null_address);
    task.add_statement(zmb::task_statement_enum::noop, address_test);
    REQUIRE(task.get_current_address() == address_test);
}