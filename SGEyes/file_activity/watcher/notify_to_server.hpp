#pragma once

#include "define.hpp"
#include <string>

SAIGON_NAMESPACE_BEGIN
class notify_to_server
{
public:
	void send(const std::wstring& action, const std::wstring& path) const;
};
SAIGON_NAMESPACE_END
