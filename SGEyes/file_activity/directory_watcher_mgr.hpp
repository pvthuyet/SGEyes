#pragma once
#include "define.hpp"
#include "task_timer.hpp"

SAIGON_NAMESPACE_BEGIN

class directory_watcher_mgr : public task_timer
{
private:
	task_timer::status on_timer() override;
};

SAIGON_NAMESPACE_END