#include "directory_watcher_mgr.hpp"
#include "fmt/format.h"
#include <iostream>

SAIGON_NAMESPACE_BEGIN

task_timer::status directory_watcher_mgr::onTimer()
{
	static int v = 0;
	std::cout << "v: " << v++ << std::endl;
	return task_timer::status::CONTINUE;
}

SAIGON_NAMESPACE_END