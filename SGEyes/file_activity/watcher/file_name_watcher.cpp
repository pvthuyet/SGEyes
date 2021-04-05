#include "file_name_watcher.hpp"
#include "logger_define.hpp"

SAIGON_NAMESPACE_BEGIN

void file_name_watcher::set_capacity(unsigned int capacity)
{
	mAdd.set_capacity(capacity);
	mRemove.set_capacity(capacity);
	mModify.set_capacity(capacity);
	mRename.set_capacity(capacity);
}

void file_name_watcher::do_notify(file_notify_info info)
{
	if (info.is_directory()) {
		//SPDLOG_INFO(L"Ignore directory");
		return;
	}
	SPDLOG_INFO(L"{} - {}", info.get_action(), info.get_path_wstring());

	switch (info.get_action())
	{
	case FILE_ACTION_ADDED:
		mAdd.push(std::move(info));
		break;

	case FILE_ACTION_REMOVED:
		mRemove.push(std::move(info));
		break;

	case FILE_ACTION_MODIFIED:
		mModify.push(std::move(info));
		break;

	case FILE_ACTION_RENAMED_OLD_NAME:
	case FILE_ACTION_RENAMED_NEW_NAME:
		mRename.push(std::move(info));
		break;

	default:
		break;
	}
}

model_rename2& file_name_watcher::get_rename()
{
	return mRename;
}

model_file_info2& file_name_watcher::get_add()
{
	return mAdd;
}

model_file_info2& file_name_watcher::get_remove()
{
	return mRemove;
}

model_file_info2& file_name_watcher::get_modify()
{
	return mModify;
}

bool file_name_watcher::exist_in_rename_any(std::wstring const& key) const
{
	return mRename.get_number_family(key) > 0;
}

SAIGON_NAMESPACE_END