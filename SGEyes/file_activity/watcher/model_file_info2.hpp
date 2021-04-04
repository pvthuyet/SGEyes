#pragma once

#include "file_notify_info.hpp"
#include "circle_map2.hpp"

SAIGON_NAMESPACE_BEGIN

class model_file_info2
{
	using file_info_map = circle_map2<std::wstring, file_notify_info>;
public:
	void set_capacity(unsigned int capacity);
	void push(file_notify_info&& info);
	file_notify_info front() const;

	file_notify_info find(std::wstring const& key) const;

	template<typename Predicate>
	file_notify_info find_if(Predicate pre) const
	{
		auto optVal = mData.find_if(pre);
		if (!optVal) {
			return mEmptyItem;
		}
		return *optVal;
	}

	void erase(std::wstring const& key);
	unsigned int next_available_item();

private:
	file_notify_info get_current_item() const;

private:
	file_info_map mData;
	file_notify_info mEmptyItem;
	unsigned int mCurrentIndex{ 0 };
};
SAIGON_NAMESPACE_END