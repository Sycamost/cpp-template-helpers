#pragma once
#include <type_traits>
#include <ostream>
#include <sstream>

template<
    class _Type,
    class _Stream = std::ostringstream,
    class _StreamElem = _Stream::char_type,
    class _StreamTraits = std::char_traits<_StreamElem>,
    std::enable_if_t<std::is_base_of_v<std::basic_ostream<_StreamElem, _StreamTraits>, _Stream>, bool> = true
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

template<class _Type, class _Stream = std::ostringstream>
inline constexpr bool is_streamable_v = is_streamable<_Type, _Stream>::value;