#pragma once
#include "define.hpp"
#include "timer.hpp"
#include "watcher/file_name_watcher.hpp"
#include "watcher/attribute_watcher.hpp"
#include "watcher/security_watcher.hpp"
#include "watcher/folder_name_watcher.hpp"
#include "watcher/notify_to_server.hpp"

SAIGON_NAMESPACE_BEGIN

class directory_watcher_mgr_impl final : public timer
{
	struct watching_group
	{
		file_name_watcher mFileName;
		attribute_watcher mAttr;
		security_watcher mSecu;
		folder_name_watcher mFolderName;
	};
	
public:
	directory_watcher_mgr_impl();
	~directory_watcher_mgr_impl() noexcept override;
	void start(unsigned long notifyChange, bool subtree = true, unsigned long interval = 300ul);

private:
	void stop() noexcept;
	timer::status on_timer() final;
	void erase_all(watching_group& group, std::wstring const& key);
	void erase_rename(watching_group& group, rename_notify_info2 const& info);

	void checking_attribute(watching_group& group);
	void checking_security(watching_group& group);
	void checking_folder_remove(watching_group& group);
	void checking_folder_move(watching_group& group);
	void checking_rename(watching_group& group);
	void checking_create(watching_group& group);
	void checking_remove(watching_group& group);
	void checking_modify(watching_group& group);
	void checking_modify_without_modify_event(watching_group& group);
	void checking_copy(watching_group& group);
	void checking_move(watching_group& group);

private:
	bool is_rename_only(rename_notify_info2 const& info, watching_group& group);
	bool is_rename_one_time(rename_notify_info2 const& info, watching_group& group);

	bool is_rename_download_auto_save(
		watching_group& group,
		rename_notify_info2 const& before,
		rename_notify_info2 const& after);
	bool is_rename_word(
		watching_group& group,
		rename_notify_info2 const& before,
		rename_notify_info2 const& after);

	bool is_temporary_file(file_notify_info const& info, watching_group& group);
	bool is_save_as_txt(file_notify_info const& info, watching_group& group);
	bool is_create_only(file_notify_info const& info, watching_group& group);

private:
	std::vector<std::unique_ptr<watching_group>> mWatchers;
	notify_to_server mSender;
};

SAIGON_NAMESPACE_END