#pragma once
#include "define.hpp"

SAIGON_NAMESPACE_BEGIN

class directory_watcher_mgr_impl;
class directory_watcher_mgr
{
public:
	~directory_watcher_mgr();
	bool start(unsigned long notifyChange, bool subtree = true, unsigned long interval = 300ul);

private:
	directory_watcher_mgr_impl* mImpl{nullptr};
};

SAIGON_NAMESPACE_END