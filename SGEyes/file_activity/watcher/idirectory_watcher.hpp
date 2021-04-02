#pragma once

#include "define.hpp"
#include "file_notify_info.hpp"

SAIGON_NAMESPACE_BEGIN
class idirectory_watcher
{
public:
	virtual ~idirectory_watcher() noexcept = default;

	void notify(file_notify_info&& info)
	{
		filter_notify(std::move(info));
	}

private:
	virtual void filter_notify(file_notify_info info) = 0;
};
SAIGON_NAMESPACE_END