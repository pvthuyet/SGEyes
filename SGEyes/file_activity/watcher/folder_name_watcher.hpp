#pragma once

#include "directory_watcher_base.hpp"
#include "model_file_info2.hpp"

SAIGON_NAMESPACE_BEGIN
class folder_name_watcher : public directory_watcher_base
{
public:
	void set_capacity(size_t capacity);
	model_file_info2& get_add();
	model_file_info2& get_remove();

private:
	void do_notify(file_notify_info info) final;

private:
	model_file_info2 mAdd;
	model_file_info2 mRemove;
};
SAIGON_NAMESPACE_END
