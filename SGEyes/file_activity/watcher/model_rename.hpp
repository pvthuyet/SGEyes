#pragma once

#include "file_notify_info.hpp"
#include "circle_map.hpp"
#include <functional>

SAIGON_NAMESPACE_BEGIN
struct rename_notify_info
{
	file_notify_info mOldName;
	file_notify_info mNewName;

	explicit operator bool() const noexcept;
	friend bool operator==(rename_notify_info const&, rename_notify_info const&);

	std::wstring get_key() const;
	bool match_any(std::wstring const& key) const;
};
bool operator==(rename_notify_info const&, rename_notify_info const&);
	
/************************************************************************************************/

class model_rename
{
	using rename_map = circle_map<std::wstring, rename_notify_info, 8u>;
public:
	void push(file_notify_info&& info);
	const rename_notify_info& front() const;

	bool is_only_one_family_info(rename_notify_info const& info) const;
	unsigned int get_number_family(std::wstring const& key) const;
	std::vector<std::reference_wrapper<const rename_notify_info>> get_family(rename_notify_info const& info) const;

	void erase(std::wstring const& key);
	unsigned int next_available_item();

private:
	rename_notify_info mInfo;
	rename_map mData;
};
SAIGON_NAMESPACE_END
