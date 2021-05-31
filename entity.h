//
// Created by snizzfox on 5/23/21.
//

#ifndef ZOMBIE_RT_ENTITY_H
#define ZOMBIE_RT_ENTITY_H

#include "dynamic_type.h"
#include "task.h"

namespace zmb {
    class entity {
        
    public:

        virtual void jump(zmb::task const & ztask, decltype(zmb::task::null_address) to_jump) = 0;
        virtual void animate() = 0;
        virtual void banish() = 0;
        virtual void disturb(zmb::entity &) = 0;
        virtual void forget() = 0;
        virtual void invoke() = 0;
        virtual void moan() = 0;
        virtual void remember(/*zmb::entity_t::zombie*/) = 0;
        virtual void remember(dynamic_type const & dynamic_type) = 0;

        void say(dynamic_type const & dynamic_type);
    };
}

#endif //ZOMBIE_RT_ENTITY_H
