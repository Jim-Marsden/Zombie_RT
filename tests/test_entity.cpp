//
// Created by snizzfox on 5/31/21.
//

#include <functional>
#include <catch2/catch.hpp>
#include "../entity.h"

TEST_CASE("zmb::entity::task_size()"){
    zmb::entity entity;

    REQUIRE(entity.task_size() == 0);

    entity.add_task({});

    REQUIRE(entity.task_size() == 1);
}

TEST_CASE("zmb::entity::empty()"){
    zmb::entity entity;
    REQUIRE(entity.empty());
    entity.add_task({});
    REQUIRE(!entity.empty());

}

TEST_CASE(" const zmb::entity::back()"){
    zmb::entity entity;
    entity.add_task({});
    auto test_lambda = [](zmb::entity const & e) -> zmb::task const &{ return e.back();};

    auto & e = test_lambda(entity);
//    e.add_statement(zmb::task_statement_enum::noop);
    auto t = e.get_current_address();
    t++;
    REQUIRE(true); // sanity check, if there's an issue i'd be cuaght at compile time.

}


