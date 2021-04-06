#pragma once

#include "define.hpp"
#include "../file_activity/watcher/rule_checker.hpp"
#include <memory>
#include <vector>

SAIGON_NAMESPACE_BEGIN
class configuration
{
public:
	static std::shared_ptr<rule_checker> load_file_activity_rules();
};
SAIGON_NAMESPACE_END