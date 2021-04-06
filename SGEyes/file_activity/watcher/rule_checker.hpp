#pragma once

#include "define.hpp"
#include "file_notify_info.hpp"
#include <vector>
#include <string>

SAIGON_NAMESPACE_BEGIN
class rule_checker
{
public:
	void add_excluded_path(std::wstring&& path);
	void add_rex_excluded_path(std::wstring&& path);

	bool is_excluded_path(file_notify_info const& info);

private:
	std::vector<std::wstring> mExcludedPaths;
	std::vector<std::wstring> mRexExcludedPaths;
};

SAIGON_NAMESPACE_END