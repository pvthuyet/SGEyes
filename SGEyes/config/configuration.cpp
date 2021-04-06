#include "configuration.hpp"
#include <nlohmann/json.hpp>
#include <fstream>

SAIGON_NAMESPACE_BEGIN

std::shared_ptr<rule_checker> configuration::load_file_activity_rules()
{
	auto ruleChecker = std::make_shared<rule_checker>();
	using json = nlohmann::json;
	std::ifstream ifs("config.json");
	auto js = json::parse(ifs);

	// 1. Parse 'excluded_paths'
	constexpr char const* EXCLUDED_PATHS = "excluded_paths";
	auto const& jExPaths = js[EXCLUDED_PATHS];
	for (auto const& el : jExPaths.items()) {
		std::string_view sv{ el.value() };
		ruleChecker->add_excluded_path(std::wstring(sv.begin(), sv.end()));
	}

	// 2. parse 'regex_excluded_paths'
	constexpr char const* REX_EXCLUDED_PATHS = "regex_excluded_paths";
	auto const& jRexExPaths = js[REX_EXCLUDED_PATHS];
	for (auto const& el : jRexExPaths.items()) {
		std::string_view sv{ el.value() };
		ruleChecker->add_rex_excluded_path(std::wstring(sv.begin(), sv.end()));
	}

	return ruleChecker;
}

SAIGON_NAMESPACE_END