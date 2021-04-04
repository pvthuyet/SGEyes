#include "folder_name_watcher.hpp"
#include "logger_define.hpp"

SAIGON_NAMESPACE_BEGIN

void folder_name_watcher::set_capacity(unsigned int capacity)
{
	mAdd.set_capacity(capacity);
	mRemove.set_capacity(capacity);
}

void folder_name_watcher::do_notify(file_notify_info info)
{
	SPDLOG_DEBUG(L"{} - {}", info.get_action(), info.get_path_wstring());
	switch (info.get_action())
	{
	case FILE_ACTION_ADDED:
		mAdd.push(std::move(info));
		break;

	case FILE_ACTION_REMOVED:
		mRemove.push(std::move(info));
		break;

	default:
		break;
	}
}

model_file_info2& folder_name_watcher::get_add()
{
	return mAdd;
}

model_file_info2& folder_name_watcher::get_remove()
{
	return mRemove;
}
SAIGON_NAMESPACE_END