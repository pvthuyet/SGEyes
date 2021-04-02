#include "directory_watcher_mgr.hpp"
#include "watcher/directory_watcher_mgr_impl.hpp"
#include "logger_define.hpp"

SAIGON_NAMESPACE_BEGIN

directory_watcher_mgr::~directory_watcher_mgr()
{
	stop();
}

bool directory_watcher_mgr::start(unsigned long notifyChange, bool subtree, unsigned long interval)
{
	LOGENTER;
	if (mWatcher) {
		// Already run
		return true;
	}
	mWatcher = new directory_watcher_mgr_impl();
	return mWatcher->start(
		FILE_NOTIFY_CHANGE_FILE_NAME
		| FILE_NOTIFY_CHANGE_LAST_WRITE
		| FILE_NOTIFY_CHANGE_DIR_NAME
		| FILE_NOTIFY_CHANGE_ATTRIBUTES
		| FILE_NOTIFY_CHANGE_SECURITY,
		subtree,
		interval
	);
	LOGEXIT;
}

void directory_watcher_mgr::stop()
{
	if (mWatcher) {
		mWatcher->stop();
		delete mWatcher;
		mWatcher = nullptr;
	}
}

SAIGON_NAMESPACE_END