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
