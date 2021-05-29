//
// Created by snizzfox on 5/21/21.
//

#include "task.h"

unsigned long zmb::task::size() {
    return data.size();
}

std::vector<zmb::task::full_statement>::iterator zmb::task::begin() noexcept {
    return data.begin();
}

std::vector<zmb::task::full_statement>::iterator zmb::task::end() noexcept {
    return data.end();
}

std::vector<zmb::task::full_statement>::const_iterator zmb::task::cbegin() const noexcept {
    return data.cbegin();
}

std::vector<zmb::task::full_statement>::const_iterator zmb::task::cend() const noexcept {
    return data.cend();
}

std::vector<zmb::task::full_statement>::const_iterator zmb::task::begin() const noexcept {
    return data.begin();
}

std::vector<zmb::task::full_statement>::const_iterator zmb::task::end() const noexcept {
    return data.end();
}

void zmb::task::add_statement(zmb::task_statement_enum taskStatementEnum, zmb::task::address_size_t addres) noexcept {
    data.push_back({taskStatementEnum, addres});
}

zmb::task::data_size_t zmb::task::get_stack_pointer() const noexcept {
    return stack_pointer;
}

void zmb::task::set_stack_pointer(zmb::task::data_size_t sp) noexcept {
    stack_pointer = sp;

}

bool zmb::task::next() noexcept {
    return (++stack_pointer <= size());
}

zmb::task_statement_enum zmb::task::get_current_instruction() const noexcept {
    return get_current_full_statement().instruction;
}

zmb::task::address_size_t zmb::task::get_current_address() const noexcept {
    return get_current_full_statement().address;
}







///////////////////////////////PRIVATE
zmb::task::full_statement zmb::task::get_current_full_statement() const noexcept {
    if(data.size() == 0 || data.size() < stack_pointer) return {zmb::task_statement_enum::noop, 0};
    else return data[stack_pointer];
}


