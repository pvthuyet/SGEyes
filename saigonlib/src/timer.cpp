#include "timer.hpp"
#include <mutex>
#include <condition_variable>

SAIGON_NAMESPACE_BEGIN

void timer::start(int interval) noexcept
{
	std::jthread tmp([interval, this](std::stop_token stoken) {
		std::mutex mutex;
		std::unique_lock lock(mutex);
		while (true) {
			// 1. Do the task
			if (status::FINISH == this->on_timer()) {
				break;
			}
	
			// 2. wait stop request
			std::condition_variable_any{}.wait_for(lock,
				stoken,
				std::chrono::milliseconds(interval),
				[&stoken] { return false; }
			);
	
			// 3. Check requested stop again
			if (stoken.stop_requested()) {
				break;
			}
		}
		});

	mWorker.swap(tmp);
}

void timer::stop() noexcept
{
	if (mWorker.joinable()) {
		mWorker.request_stop();
		mWorker.join();
	}
}

SAIGON_NAMESPACE_END