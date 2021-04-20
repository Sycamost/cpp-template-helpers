// cpp-template-helpers.cpp : Defines the entry point for the application.
//

#include <iostream>>
#include "template_helpers.h"

using namespace template_helpers;
struct S {};

int main()
{
	static_assert(can_convert_wstring_v<int>);
	static_assert(can_convert_wstring_v<int>);
	static_assert(!can_convert_wstring_v<S>);
	std::cout << convert_string(2) << std::endl;
	std::wcout << convert_wstring(3) << std::endl;
	return 0;
}
