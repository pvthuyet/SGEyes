#pragma once

#include "define.hpp"
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
	virtual status on_timer() = 0;

private:
	std::jthread mWorker;
};
SAIGON_NAMESPACE_END