#pragma once

#include "define.hpp"
#include <string>
#include <string_view>

SAIGON_NAMESPACE_BEGIN
namespace string_utils
{
	// TODO
	std::string convert_to_string(std::wstring_view s);
	std::wstring convert_to_wstring(std::string_view s);
}
SAIGON_NAMESPACE_END