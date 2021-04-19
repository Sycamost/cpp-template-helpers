// cpp-template-helpers.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#if _HAS_CXX_17

#include "is_comparison.h"
#include "is_equatable.h"
#include "is_member_of.h"
#include "is_predicate.h"
#include "is_streamable.h"
#include "convert_string.h"
#include "get_param.h"

#else

#error "template_helpers requires C++17 or greater."

#endif