#include "string_utils.hpp"
#include "../gsl/include/gsl/assert" // TODO : why ???
#include <regex>

SAIGON_NAMESPACE_BEGIN

namespace string_utils
{
	std::string convert_to_string(std::wstring_view s)
	{
		return std::string(s.cbegin(), s.cend());
	}

	std::wstring convert_to_wstring(std::string_view s)
	{
		return std::wstring(s.cbegin(), s.cend());
	}

	bool contains(std::wstring const& s, std::wstring const& ss, bool icase)
	{
		Expects(!s.empty());
		Expects(!ss.empty());
		// case insensitive
		if (icase) {
			return std::cend(s) != std::search(std::cbegin(s), std::cend(s), std::cbegin(ss), std::cend(ss), [](auto const& ch1, auto const& ch2) {
				return std::toupper(ch1) == std::toupper(ch2);
				});
		}

		// case sensitive
		return std::wstring::npos != s.find(ss);
	}

	bool rex_contains(std::wstring const& s, std::wstring const& patterm, bool icase)
	{
		Expects(!s.empty());
		Expects(!patterm.empty());
		std::wregex rex(patterm, icase ? (std::regex_constants::ECMAScript | std::regex_constants::icase) : std::regex_constants::ECMAScript);
		return std::regex_search(s, rex);
	}
}

SAIGON_NAMESPACE_END