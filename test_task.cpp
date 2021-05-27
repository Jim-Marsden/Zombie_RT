//
// Created by snizzfox on 5/23/21.
//

#define CATCH_TEST_RUNNER
#include <functional>
#include <catch2/catch.hpp>
#include "task.h"

TEST_CASE("task::invoke_task", "default"){
    bool x{};
    zmb::task task;
    task.add_statement(zmb::dynamic_type{}, zmb::task_statement_enum::test);
    std::function test = [&x](zmb::dynamic_type const &, zmb::task_statement_enum){ x = true;};
    zmb::invoke_task(task, test);
    REQUIRE(x);
}

TEST_CASE("task::add_statement", "default"){
    zmb::task task{};
    REQUIRE(task.size() == 0);
    task.add_statement({}, {});
    REQUIRE(task.size() == 1);
}