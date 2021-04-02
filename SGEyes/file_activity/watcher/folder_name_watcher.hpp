#pragma once

#include "directory_watcher_base.hpp"
#include "model_file_info.hpp"

SAIGON_NAMESPACE_BEGIN
class folder_name_watcher : public directory_watcher_base
{
public:
	model_file_info& get_add();
	model_file_info& get_remove();

private:
	void do_notify(file_notify_info info) final;

private:
	model_file_info mAdd;
	model_file_info mRemove;
};
SAIGON_NAMESPACE_END
