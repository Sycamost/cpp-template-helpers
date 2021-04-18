// cpp-template-helpers.cpp : Defines the entry point for the application.
//

#include "template_helpers.h"

int main()
{
	static_assert(is_streamable_v<const int&>, "Error!");
	static_assert(is_streamable_v<const float&>, "Error!");
	static_assert(is_streamable_v<const int*&>, "Error!");
	static_assert(is_streamable_v<const int[]>, "Error!");
	static_assert(is_streamable_v<const void*>, "Error!");
	static_assert(is_streamable_v<const void(*)()>, "Error!");
	return 0;
}
