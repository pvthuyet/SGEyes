#include "directory_watcher_mgr.hpp"
#include "logger_define.hpp"

SAIGON_NAMESPACE_BEGIN

task_timer::status directory_watcher_mgr::on_timer()
{
	LOGENTER;
	LOGEXIT;
	return task_timer::status::CONTINUE;
}

SAIGON_NAMESPACE_END