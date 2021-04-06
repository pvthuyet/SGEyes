#include "string_utils.hpp"

SAIGON_NAMESPACE_BEGIN

namespace string_utils
{
	std::string convert(std::wstring_view s)
	{
		return std::string(s.cbegin(), s.cend());
	}

	std::wstring convert(std::string_view s)
	{
		return std::wstring(s.cbegin(), s.cend());
	}
}

SAIGON_NAMESPACE_END