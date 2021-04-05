#pragma once

#include "directory_watcher_base.hpp"
#include "model_file_info2.hpp"

SAIGON_NAMESPACE_BEGIN
class security_watcher : public directory_watcher_base
{
public:
	void set_capacity(size_t capacity);
	model_file_info2& get_model();

private:
	void do_notify(file_notify_info info) final;

private:
	model_file_info2 mModel;
};
SAIGON_NAMESPACE_END
