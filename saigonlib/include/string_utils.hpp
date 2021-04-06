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

	bool contains(std::wstring const& s, std::wstring const& ss, bool icase = false);
	bool rex_contains(std::wstring const& s, std::wstring const& patterm, bool icase = false);
}
SAIGON_NAMESPACE_END