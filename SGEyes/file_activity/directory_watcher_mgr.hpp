#pragma once
#include "define.h"
#include "task_timer.hpp"

SAIGON_NAMESPACE_BEGIN

class directory_watcher_mgr : public task_timer
{
private:
	task_timer::status onTimer() override;
};

SAIGON_NAMESPACE_END