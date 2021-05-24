//
// Created by snizzfox on 5/21/21.
//

#ifndef ZOMBIE_RT_TASK_H
#define ZOMBIE_RT_TASK_H
#include "zombie_statements.hpp"
#include "dynamic_type.h"

#include <vector>
#include <string>
namespace zmb {


    class task {
        struct full_statement{dynamic_type type; task_statement_enum statement; };
        std::string task_name;
        std::vector<full_statement> data;

    };
}// namespace zmb

#endif //ZOMBIE_RT_TASK_H
