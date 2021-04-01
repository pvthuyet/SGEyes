#pragma once

#include "define.h"
#include <thread>

SAIGON_NAMESPACE_BEGIN
enum class TimerStatus
{
	TIMER_CONTINUE,
	TIMER_FINISH
};

class TaskTimer
{
public:
	virtual ~TaskTimer() noexcept {};

	void start(int interval) noexcept;
	void stop() noexcept;

private:
	//virtual TimerStatus onTimer() = 0;

public:
	void execute(std::stop_token stoken);

private:
	std::jthread mWorker;
};
SAIGON_NAMESPACE_END