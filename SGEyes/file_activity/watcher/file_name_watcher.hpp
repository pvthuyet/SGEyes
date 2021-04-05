#pragma once

#include "directory_watcher_base.hpp"
#include "model_rename2.hpp"
#include "model_file_info2.hpp"

SAIGON_NAMESPACE_BEGIN
class file_name_watcher : public directory_watcher_base
{
public:
	void set_capacity(size_t capacity);
	model_file_info2& get_add();
	model_file_info2& get_remove();
	model_file_info2& get_modify();
	model_rename2& get_rename();
	bool exist_in_rename_any(std::wstring const& key) const;

private:
	void do_notify(file_notify_info info) final;

private:
	model_file_info2 mAdd;
	model_file_info2 mRemove;
	model_file_info2 mModify;
	model_rename2 mRename;
};
SAIGON_NAMESPACE_END