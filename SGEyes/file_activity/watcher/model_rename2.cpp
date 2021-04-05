#include "model_rename2.hpp"
#include <Windows.h>

SAIGON_NAMESPACE_BEGIN
rename_notify_info2::operator bool() const noexcept
{
	return static_cast<bool>(mOldName)
		&& static_cast<bool>(mNewName)
		&& (mOldName.get_parent_path_wstring() == mNewName.get_parent_path_wstring());
}

std::wstring rename_notify_info2::get_key() const
{
	return mOldName.get_path_wstring() + mNewName.get_path_wstring();
}

bool rename_notify_info2::match_any(std::wstring const& key) const
{
	return key == mOldName.get_path_wstring()
		|| key == mNewName.get_path_wstring();
}

bool operator==(rename_notify_info2 const& lhs, rename_notify_info2 const& rhs)
{
	return lhs.mOldName == rhs.mOldName && lhs.mNewName == rhs.mNewName;
}

/************************************************************************************************/

void model_rename2::set_capacity(unsigned int capacity)
{
	mData.set_capacity(capacity);
}

void model_rename2::push(file_notify_info&& info)
{
	switch (info.get_action())
	{
	case FILE_ACTION_RENAMED_OLD_NAME:
		mInfo.mOldName = std::move(info);
		break;

	case FILE_ACTION_RENAMED_NEW_NAME:
		mInfo.mNewName = std::move(info);
		break;

	default:
		break;
	}

	// valid data
	if (mInfo) {
		mData.push_back(mInfo.get_key(), std::move(mInfo));
	}
}

rename_notify_info2 model_rename2::front() const
{
	return get_current_item();
}

bool model_rename2::is_only_one_family_info(rename_notify_info2 const& info) const
{
	unsigned int family = 0;
	auto oldName = info.mOldName.get_path_wstring();
	auto newName = info.mNewName.get_path_wstring();

	mData.traversal([&oldName, &newName, &family](auto const& item) {
		if (item.second.match_any(oldName) || item.second.match_any(newName)) {
			++family;
		}
	});
	return 1u == family;
}

unsigned int model_rename2::get_number_family(std::wstring const& key) const
{
	unsigned int family = 0;
	mData.traversal([&key, &family](auto const& item) {
		if (item.second.match_any(key)) {
			++family;
		}
	});
	return family;
}

std::vector<std::reference_wrapper<const rename_notify_info2>> model_rename2::get_family(rename_notify_info2 const& info) const
{
	std::vector<std::reference_wrapper<const rename_notify_info2>> family;
	auto oldName = info.mOldName.get_path_wstring();
	auto newName = info.mNewName.get_path_wstring();
	mData.traversal([&oldName, &newName, &family](auto const& item) {
		if (item.second.match_any(oldName) || item.second.match_any(newName)) {
			family.push_back(item.second);
		}
	});
	return family;
}

void model_rename2::erase(std::wstring const& key)
{
	mData.erase(key);
}

unsigned int model_rename2::next_available_item()
{
	auto sz = mData.size();
	if (sz > 0) {
		mCurrentIndex = (mCurrentIndex + 1u) % sz;
	}
	return mCurrentIndex;
}

rename_notify_info2 model_rename2::get_current_item() const
{
	auto item = mData.at(mCurrentIndex);
	if (!item) {
		return mEmptyItem;
	}
	return item->second;
}
SAIGON_NAMESPACE_END