#pragma once
#include <type_traits>
#include <ostream>
#include <string>

#if _HAS_CXX17


namespace template_helpers
{

    template<
        typename _Type,
        typename _Stream = std::ostringstream,
        typename _StreamElem = std::ostringstream::char_type,
        typename _StreamTraits = std::char_traits<_StreamElem>,
        std::enable_if_t<std::is_base_of_v<std::basic_ostringstream<_StreamElem, _StreamTraits>, _Stream>, bool> = true
    >
    class is_streamable
    {
        template<typename __Type, typename __Stream>
        static auto test(int)
            -> decltype(std::declval<__Stream&>() << std::declval<__Type>(), std::true_type());

        template<typename, typename>
        static auto test(...)->std::false_type;

    public:
        static const bool value = decltype(test<_Type, _Stream>(0))::value;
    };

    template<typename _Type, typename _Stream = std::ostringstream>
    inline constexpr bool is_streamable_v = is_streamable<_Type, _Stream>::value;

    template<
        typename _Type,
        typename _Stream = std::wostringstream,
        std::enable_if_t<std::is_base_of_v<std::basic_ostringstream<wchar_t, std::char_traits<wchar_t>>, _Stream>, bool> = true
    >
    using is_w_streamable = is_streamable<_Type, _Stream, wchar_t, std::char_traits<wchar_t>>;

    template<typename _Type, typename _Stream = std::wostringstream>
    inline constexpr bool is_w_streamable_v = is_w_streamable<_Type, _Stream>::value;

}

#else

#error "template_helpers requires C++17 or greater."

#endif