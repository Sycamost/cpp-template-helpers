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

    template<class T, std::enable_if_t<std::is_convertible_v<T, std::wstring>, bool> = true>
    std::wstring convert_wstring(T t) {
        return static_cast<std::wstring>(t);
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

    template <
        class T,
        std::enable_if_t<
            std::conjunction_v<
                std::negation<std::is_convertible<T, std::wstring>>,
                is_w_streamable<T>
            >,
            bool
        > = true
    >
    std::wstring convert_wstring(T t) {
        std::wostringstream stream = std::wostringstream();
        stream << t;
        return stream.str();
    }

    template<typename T>
    using can_convert_string = std::disjunction<std::is_convertible<T, std::string>, is_streamable<T>>;

    template<typename T>
    inline constexpr bool can_convert_string_v = can_convert_string<T>::value;

    template<typename T>
    using can_convert_wstring = std::disjunction<std::is_convertible<T, std::wstring>, is_w_streamable<T>>;

    template<typename T>
    inline constexpr bool can_convert_wstring_v = can_convert_wstring<T>::value;

}