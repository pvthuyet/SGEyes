#include "task_timer.hpp"
#include "fmt/format.h"
#include <mutex>
#include <condition_variable>
#include <iostream>

SAIGON_NAMESPACE_BEGIN

void TaskTimer::start(int interval) noexcept
{
	std::jthread tmp([](std::stop_token stoken) {
		std::cout << "hello from jthread\n";
		});

	mWorker.swap(tmp);
}

void TaskTimer::stop() noexcept
{
	mWorker.request_stop();
}

void TaskTimer::execute(std::stop_token stoken)
{
	//std::mutex mutex;
	//std::unique_lock lock(mutex);

	//while (true) {
	//	// 1. Do the task
	//	if (TimerStatus::TIMER_FINISH == onTimer()) {
	//		break;
	//	}

	//	// 2. wait stop request
	//	std::condition_variable_any{}.wait_for(lock,
	//		stoken,
	//		std::chrono::milliseconds(3000),
	//		[&stoken] { return false; }
	//	);

	//	// 3. Check requested stop again
	//	if (stoken.stop_requested()) {
	//		break;
	//	}
	//}
}
SAIGON_NAMESPACE_END