#pragma once

#include "define.hpp"
#include <string>

SAIGON_NAMESPACE_BEGIN
struct watching_setting
{
public:
	watching_setting() noexcept = default;
	watching_setting(unsigned long action, std::wstring dir, bool subtree = true);

	bool valid() const;
	friend bool operator==(watching_setting const&, watching_setting const&);

public:
	bool mSubtree{};
	unsigned long mAction{};
	std::wstring mDirectory;
};

bool operator==(watching_setting const& lhs, watching_setting const& rhs);
SAIGON_NAMESPACE_END