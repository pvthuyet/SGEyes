#include "notify_to_server.hpp"
#include "logger_define.hpp"

SAIGON_NAMESPACE_BEGIN
void notify_to_server::send(const std::wstring& action, const std::wstring& path) const
{
	SPDLOG_INFO(L"{} - {}", action, path);
}
SAIGON_NAMESPACE_END