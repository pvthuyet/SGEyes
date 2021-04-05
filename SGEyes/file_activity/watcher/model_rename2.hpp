#pragma once

#include "file_notify_info.hpp"
#include "circle_map2.hpp"
#include <functional>

SAIGON_NAMESPACE_BEGIN
struct rename_notify_info2
{
	file_notify_info mOldName;
	file_notify_info mNewName;

	explicit operator bool() const noexcept;
	friend bool operator==(rename_notify_info2 const&, rename_notify_info2 const&);

	std::wstring get_key() const;
	bool match_any(std::wstring const& key) const;
};
bool operator==(rename_notify_info2 const&, rename_notify_info2 const&);
	
/************************************************************************************************/

class model_rename2
{
	using rename_map = circle_map2<std::wstring, rename_notify_info2>;
public:
	void set_capacity(unsigned int capacity);
	void push(file_notify_info&& info);
	rename_notify_info2 front() const;

	bool is_only_one_family_info(rename_notify_info2 const& info) const;
	unsigned int get_number_family(std::wstring const& key) const;
	std::vector<std::reference_wrapper<const rename_notify_info2>> get_family(rename_notify_info2 const& info) const;

	void erase(std::wstring const& key);
	unsigned int next_available_item();

private:
	rename_notify_info2 get_current_item() const;

private:
	rename_notify_info2 mInfo;
	rename_map mData;
	rename_notify_info2 mEmptyItem;
	unsigned int mCurrentIndex{ 0 };
};
SAIGON_NAMESPACE_END
