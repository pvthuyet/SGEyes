#include "rule_checker.hpp"

SAIGON_NAMESPACE_BEGIN
void rule_checker::add_excluded_path(std::wstring&& path)
{
	mExcludedPaths.emplace_back(std::move(path));
}

void rule_checker::add_rex_excluded_path(std::wstring&& path)
{
	mRexExcludedPaths.emplace_back(path);
}

bool rule_checker::is_excluded_path(file_notify_info const& info)
{
	return false;
}

SAIGON_NAMESPACE_END