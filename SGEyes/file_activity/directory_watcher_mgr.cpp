#include "directory_watcher_mgr.hpp"
#include "fmt/format.h"
#include <iostream>

SAIGON_NAMESPACE_BEGIN

task_timer::status directory_watcher_mgr::on_timer()
{
	static int v = 0;
	fmt::print("v: {}", v++);
	return task_timer::status::CONTINUE;
}

SAIGON_NAMESPACE_END