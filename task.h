//
// Created by snizzfox on 5/21/21.
//

#ifndef ZOMBIE_RT_TASK_H
#define ZOMBIE_RT_TASK_H

#include "zombie_statements.hpp"
#include "dynamic_type.h"

#include <vector>
#include <string>
#include <iostream>

namespace zmb {


    class task {
        struct full_statement {
            dynamic_type type;
            task_statement_enum statement;
        };
        std::vector<full_statement> data;

    public:
        task() = default;

        ~task() = default;

        task(task const &) = default;

        task(task &&) = default;

        task &operator=(task const &) = default;

        [[nodiscard]] decltype(data)::size_type size();

        [[nodiscard]] decltype(data)::iterator begin() noexcept;

        [[nodiscard]] decltype(data)::iterator end() noexcept;

        [[nodiscard]] decltype(data)::const_iterator cbegin() const noexcept;

        [[nodiscard]] decltype(data)::const_iterator cend() const noexcept;

        [[nodiscard]] decltype(data)::const_iterator begin() const noexcept;

        [[nodiscard]] decltype(data)::const_iterator end() const noexcept;

        void add_statement(dynamic_type const &, task_statement_enum taskStatementEnum) noexcept;


    };

    template<class invokeable_t>
    auto invoke_task(task const &taskv,  invokeable_t invokeable) {
        if(invokeable == nullptr)return false;
        for (auto &e :  taskv) {
            invokeable(e.type, e.statement);
        }
        return true;
    }


}// namespace zmb

#endif //ZOMBIE_RT_TASK_H
