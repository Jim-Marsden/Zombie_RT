//
// Created by snizzfox on 5/23/21.
//

#define CATCH_TEST_RUNNER

#include <catch2/catch.hpp>
#include "task.h"

TEST_CASE("invoke_task", "default"){
    bool x{};
    zmb::task task;
    task.add_statement(zmb::dynamic_type{}, zmb::task_statement_enum::test);
    zmb::invoke_task(task, [&x](auto a, auto b){x = true;});
    REQUIRE(x);
}