#pragma once
#include <type_traits>
#include <string>
#include <sstream>
#include "is_streamable.h"

namespace template_helpers
{

    template<class T, std::enable_if_t<std::is_convertible_v<T, std::string>, bool> = true>
    std::string convert_string(T t) {
        return static_cast<std::string>(t);
    }

    template <
        class T,
        std::enable_if_t<
        std::conjunction_v<
        std::negation<std::is_convertible<T, std::string>>,
        is_streamable<T>
        >,
        bool
        > = true
    >
        std::string convert_string(T t) {
        std::ostringstream stream = std::ostringstream();
        stream << t;
        return stream.str();
    }

    template<class T>
    using can_convert_string = std::disjunction<std::is_convertible<T, std::string>, is_streamable<T>>;

    template<class T>
    inline constexpr bool can_convert_string_v = can_convert_string<T>::value;

}