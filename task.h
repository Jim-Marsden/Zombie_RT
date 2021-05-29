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
#include <limits>

namespace zmb {

    class task {
        using address_size_t = short unsigned;
        struct full_statement {
            task_statement_enum instruction{};
            address_size_t address{};
        };
        std::vector<full_statement> data;

        using data_size_t = decltype(data)::size_type;

        data_size_t stack_pointer{};

        [[nodiscard]] full_statement get_current_full_statement() const noexcept;



    public:

//        static constexpr address_size_t get_max();
        static constexpr auto max_size{std::numeric_limits<address_size_t>::max()};
        constexpr static address_size_t null_address{max_size};


        task() = default;

        ~task() = default;

        task(task const &) = default;

        task(task &&) = default;

        task &operator=(task const &) = default;

        [[nodiscard]] data_size_t size();

        [[nodiscard]] decltype(data)::iterator begin() noexcept;

        [[nodiscard]] decltype(data)::iterator end() noexcept;

        [[nodiscard]] decltype(data)::const_iterator cbegin() const noexcept;

        [[nodiscard]] decltype(data)::const_iterator cend() const noexcept;

        [[nodiscard]] decltype(data)::const_iterator begin() const noexcept;

        [[nodiscard]] decltype(data)::const_iterator end() const noexcept;

        void add_statement(task_statement_enum taskStatementEnum, address_size_t address=0) noexcept;

        [[nodiscard]] data_size_t get_stack_pointer() const noexcept;

        void set_stack_pointer(data_size_t) noexcept;

        bool next() noexcept;

        [[nodiscard]] task_statement_enum get_current_instruction() const noexcept;

        [[nodiscard]] address_size_t get_current_address() const noexcept;

    };



}// namespace zmb

#endif //ZOMBIE_RT_TASK_H
