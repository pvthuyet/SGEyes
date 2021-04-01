#pragma once

#include "define.h"
#include <thread>

SAIGON_NAMESPACE_BEGIN

class task_timer
{
public:
	enum class status
	{
		CONTINUE,
		FINISH
	};

public:
	virtual ~task_timer() noexcept {};

	void start(int interval) noexcept;
	void stop() noexcept;

private:
	virtual status onTimer() = 0;

private:
	std::jthread mWorker;
};
SAIGON_NAMESPACE_END