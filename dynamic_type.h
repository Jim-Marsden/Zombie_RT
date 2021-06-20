//
// Created by snizzfox on 5/21/21.
//

#ifndef ZOMBIE_RT_DYNAMIC_TYPE_H
#define ZOMBIE_RT_DYNAMIC_TYPE_H

#include <variant>
#include <string>

namespace zmb {

    class dynamic_type {
        using numeric_type = double;
        using string_type = std::string;
        std::variant<numeric_type, string_type> data;
    public:
        ~dynamic_type() = default;

        dynamic_type() = default;

        dynamic_type(dynamic_type const &) = default;

        dynamic_type(dynamic_type &&) = default;

        dynamic_type &operator=(dynamic_type const &) = default;

        explicit dynamic_type(numeric_type const &numericType) noexcept;

        explicit dynamic_type(string_type const &stringType) noexcept;

        explicit operator string_type() const;

        explicit operator numeric_type() const;

        [[nodiscard]] bool check_type_is_str() const;

        [[nodiscard]] bool check_type_is_num() const;

        void set(numeric_type const &numericType);

        void set(string_type const &stringType);

        [[nodiscard]] string_type get_as_string() const noexcept;

        [[nodiscard]] numeric_type get_as_numeric() const noexcept;

        void clear() noexcept;

    };
}

#endif //ZOMBIE_RT_DYNAMIC_TYPE_H
