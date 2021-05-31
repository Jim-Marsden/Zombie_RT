//
// Created by snizzfox on 5/23/21.
//

#include "entity.h"

zmb::task const & zmb::entity::back() const noexcept
{
    return tasks.back();
}

zmb::task& zmb::entity::back() noexcept
{
    return tasks.back();
}

void zmb::entity::add_task(const zmb::task& task_in) noexcept
{
    tasks.push_back(task_in);
}

decltype(zmb::entity::tasks.size()) zmb::entity::task_size() const noexcept
{
    return tasks.size();
}

bool zmb::entity::empty() const noexcept
{
    return tasks.empty();
}
