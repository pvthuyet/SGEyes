#include "model_file_info2.hpp"

SAIGON_NAMESPACE_BEGIN

void set_capacity(unsigned int capacity)
{
	mData.set_capacity(capacity);
}

void model_file_info2::push(file_notify_info&& info)
{
	mData.push_back(info.get_path_wstring(), std::move(info))
}

file_notify_info model_file_info2::front() const
{
	return get_current_item();
}

file_notify_info model_file_info2::find(std::wstring const& key) const
{
	auto optVal = mData.find(key);
	if (!optVal) {
		return mEmptyItem;
	}
	return *optVal;
}

void model_file_info2::erase(std::wstring const& key)
{
	mData.erase(key);
}

file_notify_info model_file_info2::get_current_item() const
{
	auto item = mData.at(mCurrentIndex);
	if (!item) {
		return mEmptyItem;
	}
	return item->second;
}

unsigned int model_file_info2::next_available_item()
{
	mCurrentIndex = (mCurrentIndex + 1) % mData.size();
	return mCurrentIndex;
}

SAIGON_NAMESPACE_END