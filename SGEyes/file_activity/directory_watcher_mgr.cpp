#include "directory_watcher_mgr.hpp"
#include "watcher/directory_watcher_mgr_impl.hpp"
#include "logger_define.hpp"

SAIGON_NAMESPACE_BEGIN

directory_watcher_mgr::~directory_watcher_mgr()
{
	LOGENTER;
	if (mImpl) {
		delete mImpl;
	}
	LOGEXIT;
}

bool directory_watcher_mgr::start(unsigned long notifyChange, bool subtree, unsigned long interval)
{
	LOGENTER;
	if (mImpl) {
		// Already run
		return true;
	}

	mImpl = new directory_watcher_mgr_impl();
	mImpl->start(notifyChange, subtree, interval);
	LOGEXIT;
}

SAIGON_NAMESPACE_END