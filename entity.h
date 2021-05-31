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

        std::vector <zmb::task> tasks;

        
    public:

        virtual ~entity() = default;
        entity() = default;

        entity(entity const &)=default;
        entity(entity &&)=default;
        entity & operator=(entity const &) = default;


        [[nodiscard]] decltype(tasks.size()) task_size() const noexcept;


        void add_task(zmb::task const & task_in) noexcept;

        //Will push_back if true;
        [[nodiscard]] task const & back() const noexcept;
        [[nodiscard]] task & back() noexcept;


    };
}

#endif //ZOMBIE_RT_ENTITY_H
