#include "directory_watcher_mgr.hpp"
#include "logger_define.hpp"

#ifdef IS_MSVC_CXX_COMPILER
#include "watcher/directory_watcher_mgr_impl.hpp"

SAIGON_NAMESPACE_BEGIN

directory_watcher_mgr::~directory_watcher_mgr()
{
	LOGENTER;
	if (mImpl) {
		delete mImpl;
	}
	LOGEXIT;
}

void directory_watcher_mgr::start(unsigned long notifyChange, bool subtree, unsigned long interval)
{
	LOGENTER;
	if (!mImpl) {
		mImpl = new directory_watcher_mgr_impl();
		mImpl->start(notifyChange, subtree, interval);
	}
	LOGEXIT;
}

SAIGON_NAMESPACE_END
#else

SAIGON_NAMESPACE_BEGIN
directory_watcher_mgr::~directory_watcher_mgr()
{
	LOGENTER;
	LOGEXIT;
}

void directory_watcher_mgr::start(unsigned long notifyChange, bool subtree, unsigned long interval)
{
	LOGENTER;
	LOGEXIT;
}
SAIGON_NAMESPACE_END

#endif //IS_MSVC_CXX_COMPILER