#pragma once
#include <type_traits>

#if _HAS_CXX17


namespace template_helpers
{

	template <typename _Callable, typename _Type, typename... _Args>
	using is_member_of = std::conjunction<
		std::is_member_pointer<_Callable>,
		std::is_invocable<_Callable, _Type, _Args...>
	>;

	template <typename _Callable, typename _Type, typename... _Args>
	static const bool constexpr is_member_of_v = is_member_of<_Callable, _Type, _Args...>::value;

	template <typename _Callable, typename _Type, typename... _Args>
	using is_const_member_of = std::conjunction<
		std::is_member_pointer<_Callable>,
		std::is_invocable<_Callable, const _Type, _Args...>
	>;

	template <typename _Callable, typename _Type, typename... _Args>
	static const bool constexpr is_const_member_of_v = is_const_member_of<_Callable, _Type, _Args...>::value;

}

#else

#error "template_helpers requires C++17 or greater."

#endif