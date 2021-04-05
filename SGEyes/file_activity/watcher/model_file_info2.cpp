#include "model_file_info2.hpp"

SAIGON_NAMESPACE_BEGIN

void model_file_info2::set_capacity(size_t capacity)
{
	mData.set_capacity(capacity);
}

void model_file_info2::push(file_notify_info&& info)
{
	mData.push_back(info.get_path_wstring(), std::move(info));
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

size_t model_file_info2::next_available_item()
{
	auto sz = mData.size();
	if (sz > 0) {
		mCurrentIndex = (mCurrentIndex + 1u) % sz;
	}
	return mCurrentIndex;
}

SAIGON_NAMESPACE_END