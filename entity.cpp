//
// Created by snizzfox on 5/23/21.
//

#include "entity.h"
#include <exception>
#include <iostream>

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
    this->current_index = 0;
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

void zmb::entity::test() {
    throw std::runtime_error("not implemented!");
}

void zmb::entity::noop() {}

void zmb::entity::unknown() {
    throw std::runtime_error("not implemented!");

}

void zmb::entity::jump(const zmb::dynamic_type &to_jump) {
    tasks[current_index].set_stack_pointer(static_cast<zmb::task::address_size_t>(to_jump.get_as_numeric()));
}

void zmb::entity::loop(const zmb::dynamic_type &test_condition) {
    throw std::runtime_error("not implemented!");
}

void zmb::entity::animate() {
    throw std::runtime_error("not implemented!");
}

void zmb::entity::banish() {
    throw std::runtime_error("not implemented!");
}

void zmb::entity::disturb(unsigned short index) {
    throw std::runtime_error("not implemented!");
}

void zmb::entity::forget() {
    memory.clear();

}

void zmb::entity::invoke() {
    throw std::runtime_error("not implemented!");


}

zmb::dynamic_type zmb::entity::moan(zmb::dynamic_type const & data2) {
    auto temp{memory};
    memory = data2;
    return temp;

}

void zmb::entity::remember(const zmb::dynamic_type &to_remeber) {
    memory = to_remeber;


}

void zmb::entity::say(const zmb::dynamic_type &to_say) {
    if(to_say.check_type_is_num()) std::cout << to_say.get_as_numeric();
    else std::cout << to_say.get_as_string();
    std::cout << '\n';

    //std::cout << (to_say.check_type_is_num() ? to_say.get_as_numeric() : to_say.get_as_string()) << "\n";


}

bool zmb::entity::next_task() noexcept {
    if(tasks.size() == (current_index + 1)) return false;
    current_index++;
    return true;
}
