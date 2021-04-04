#include "attribute_watcher.hpp"
#include "logger_define.hpp"

SAIGON_NAMESPACE_BEGIN
void attribute_watcher::set_capacity(unsigned int capacity)
{
	mModel.set_capacity(capacity);
}

void attribute_watcher::do_notify(file_notify_info info)
{
	switch (info.get_action())
	{
	case FILE_ACTION_MODIFIED:
		SPDLOG_DEBUG(L"{} - {}", info.get_action(), info.get_path_wstring());
		mModel.push(std::move(info));
		break;

	default:
		SPDLOG_DEBUG(L"Ignore: {} - {}", info.get_action(), info.get_path_wstring());
		break;
	}
}

model_file_info2& attribute_watcher::get_model()
{
	return mModel;
}
SAIGON_NAMESPACE_END