//
// Created by snizzfox on 5/23/21.
//

#ifndef ZOMBIE_RT_ENTITY_H
#define ZOMBIE_RT_ENTITY_H

#include "dynamic_type.h"
#include "task.h"

#include <vector>

namespace zmb {
    class entity {
        dynamic_type memory;

        std::vector<zmb::task> tasks;

        std::vector<zmb::task>::size_type current_index;


    public:
        virtual ~entity() = default;

        entity() = default;

        entity(entity const &) = default;

        entity(entity &&) = default;

        entity& operator=(entity const &) = default;


        [[nodiscard]] decltype(tasks.size()) task_size() const noexcept;

        [[nodiscard]] bool empty() const noexcept;


        void virtual add_task(zmb::task const &task_in) noexcept;
        bool virtual next_task() noexcept; // true if it goes to next task


        //Will push_back if true;
        [[nodiscard]] task const &back() const noexcept;

        [[nodiscard]] task &back() noexcept;

        virtual void test();
        virtual void jump(zmb::dynamic_type const& to_jump);
        virtual void loop(zmb::dynamic_type const& test_condition);
        virtual void noop();
        virtual void unknown();
        virtual void animate();
        virtual void banish();
        virtual void disturb(unsigned short index);
        virtual void forget();
        virtual void invoke();
        virtual zmb::dynamic_type moan(zmb::dynamic_type const & data2);
        virtual void remember(zmb::dynamic_type const& to_remeber);
        virtual void say(zmb::dynamic_type const& to_say);

    };
}

#endif //ZOMBIE_RT_ENTITY_H
