//
// Created by snizzfox on 5/26/21.
//

#ifndef ZOMBIE_RT_TASK_FUNCTIONS_H
#define ZOMBIE_RT_TASK_FUNCTIONS_H

#include "dynamic_type.h"
#include "task.h"
namespace zmb{

            [[nodiscard]] std::size_t jump(zmb::task const & ztask);
            void animate(/*zmb::entity_t::zombie*/);
            void banish(/*zmb::entity_t::zombie*/);
            void disturb(/*zmb::entity_t::zombie*/);
            void forget(/*zmb::entity_t::zombie*/);
            void invoke(/*zmb::entity_t::zombie*/);
            void moan(/*zmb::entity_t::zombie*/);
            void remember(/*zmb::entity_t::zombie*/);
            void remember(dynamic_type const & dynamic_type);

            void say(dynamic_type const & dynamic_type);

} // namespace zmb

#endif //ZOMBIE_RT_TASK_FUNCTIONS_H
