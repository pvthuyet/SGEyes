#pragma once

#include "idirectory_watcher.hpp"
#include "iobserver.hpp"
#include "watching_setting.hpp"
#include "rule_checker.hpp"
#include <Windows.h>

SAIGON_NAMESPACE_BEGIN

class directory_watcher_base : public idirectory_watcher
{
public:
	directory_watcher_base() noexcept = default;
	~directory_watcher_base() noexcept override;

	void set_rule(std::shared_ptr<rule_checker>);

	bool add_setting(watching_setting&& sett);

	bool start();
	void stop() noexcept;

	// movable
	directory_watcher_base(directory_watcher_base&&) noexcept;
	directory_watcher_base& operator=(directory_watcher_base&&) noexcept;

private:
	void filter_notify(file_notify_info info) final;
	virtual void do_notify(file_notify_info info) = 0;

private:
	std::vector<watching_setting> mSettings;
	HANDLE mObserverThread{ nullptr };
	unsigned mThreadId{};
	std::unique_ptr<iobserver> mObserver{};
	std::shared_ptr<rule_checker> mRuleChecker;
};

SAIGON_NAMESPACE_END