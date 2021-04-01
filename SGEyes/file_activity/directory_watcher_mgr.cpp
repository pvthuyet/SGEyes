#include "directory_watcher_mgr.hpp"
#include "spdlog_header.h"

SAIGON_NAMESPACE_BEGIN

task_timer::status directory_watcher_mgr::on_timer()
{
	LOGENTER;
	int* x = new int(1);
	//*x = 2;
	LOGEXIT;
	return task_timer::status::CONTINUE;
}

SAIGON_NAMESPACE_END