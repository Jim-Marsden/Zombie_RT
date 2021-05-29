//
// Created by snizzfox on 5/23/21.
//

#define CATCH_TEST_RUNNER
#include <functional>
#include <catch2/catch.hpp>
#include "task.h"


TEST_CASE("zmb::task::add_statement", "default"){
    zmb::task task;
    task.add_statement(zmb::task_statement_enum::test);
}