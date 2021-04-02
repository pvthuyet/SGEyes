#pragma once

#include "directory_watcher_base.hpp"
#include "model_file_info.hpp"

SAIGON_NAMESPACE_BEGIN
class attribute_watcher : public directory_watcher_base
{
public:
	model_file_info& get_model();

private:
	void do_notify(file_notify_info info) final;

private:
	model_file_info mModel;
};
SAIGON_NAMESPACE_END
