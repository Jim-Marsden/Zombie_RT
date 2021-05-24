//
// Created by snizzfox on 5/21/21.
//

#include <stdexcept>
#include "dynamic_type.h"

zmb::dynamic_type::dynamic_type(const zmb::dynamic_type::numeric_type &numericType) noexcept : data{numericType} {}

zmb::dynamic_type::dynamic_type(const zmb::dynamic_type::string_type &stringType) noexcept : data{stringType} {}

zmb::dynamic_type::operator string_type() const {
    return std::get<string_type>(data);
}

zmb::dynamic_type::operator numeric_type() const {
    return std::get<numeric_type>(data);
}

void zmb::dynamic_type::set(const zmb::dynamic_type::numeric_type &numericType) {
    data = numericType;
}

void zmb::dynamic_type::set(const zmb::dynamic_type::string_type &stringType) {
    data = stringType;
}

bool zmb::dynamic_type::check_type_is_str() const {
    if(data.index() == 1)return true;
    else return false;
}

bool zmb::dynamic_type::check_type_is_num() const {
    if(data.index() == 0) return true;
    else return false;
}

zmb::dynamic_type::string_type zmb::dynamic_type::get_as_string() const noexcept {
    if(check_type_is_str()){
        return std::get<string_type>(data);
    }
    else{
        return std::to_string(std::get<numeric_type>(data));
    }
}

zmb::dynamic_type::numeric_type zmb::dynamic_type::get_as_numeric() const noexcept {
    if(check_type_is_num()){
        return std::get<numeric_type>(data);
    }
    else{
        try {
            return std::stod(std::get<string_type>(data));
        }
        catch(std::invalid_argument const &e){
            return {};
        }
    }
}
