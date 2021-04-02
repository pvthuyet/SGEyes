#include "watching_setting.hpp"

SAIGON_NAMESPACE_BEGIN
watching_setting::watching_setting(unsigned long action, std::wstring dir, bool subtree) : 
	mSubtree{ subtree },
	mAction { action },
	mDirectory {dir}
{}

bool watching_setting::valid() const 
{ 
	return mAction > 0 && !mDirectory.empty(); 
}

bool operator==(watching_setting const& lhs, watching_setting const& rhs)
{
	return lhs.mSubtree		== rhs.mSubtree
		&& lhs.mAction		== rhs.mAction
		&& lhs.mDirectory	== rhs.mDirectory;
}
SAIGON_NAMESPACE_END