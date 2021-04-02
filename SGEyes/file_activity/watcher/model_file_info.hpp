#pragma once

#include "file_notify_info.hpp"
#include "circle_map.hpp"

SAIGON_NAMESPACE_BEGIN

class model_file_info
{
	using file_info_map = circle_map<std::wstring, file_notify_info, 8u>;
public:
	void push(file_notify_info&& info);
	const file_notify_info& front() const;

	const file_notify_info& find(std::wstring const& key) const;

	template<typename Predicate>
	const file_notify_info& find_if(Predicate pre) const
	{
		return mData.find_if(pre);
	}

	void erase(std::wstring const& key);
	unsigned int next_available_item();

private:
	file_info_map mData;
};
SAIGON_NAMESPACE_END