#pragma once
#include "define.hpp"
#include <memory>

SAIGON_NAMESPACE_BEGIN

class directory_watcher_mgr_impl;
class directory_watcher_mgr
{
public:
	directory_watcher_mgr();
	~directory_watcher_mgr();
	void start(unsigned long notifyChange, bool subtree = true, unsigned long interval = 300ul);

private:
	std::unique_ptr<directory_watcher_mgr_impl> mImpl;
};

SAIGON_NAMESPACE_END