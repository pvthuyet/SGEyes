#include "rule_checker.hpp"
#include "string_utils.hpp"
#include <nlohmann/json.hpp>
#include <fstream>

SAIGON_NAMESPACE_BEGIN

void rule_checker::load()
{
	using json = nlohmann::json;
	std::ifstream ifs("config.json");
	auto js = json::parse(ifs);

	// 1. Parse 'excluded_paths'
	constexpr char const* EXCLUDED_PATHS = "excluded_paths";
	auto const& jExPaths = js[EXCLUDED_PATHS];
	for (auto const& el : jExPaths.items()) {
		// TODO
		std::string jstr = el.value();
		mExcludedPaths.push_back(string_utils::convert(std::string_view(jstr)));
	}

	// 2. parse 'regex_excluded_paths'
	constexpr char const* REX_EXCLUDED_PATHS = "regex_excluded_paths";
	auto const& jRexExPaths = js[REX_EXCLUDED_PATHS];
	for (auto const& el : jRexExPaths.items()) {
		// TODO
		std::string jstr = el.value();
		mRexExcludedPaths.push_back(string_utils::convert(std::string_view(jstr)));
	}
}

bool rule_checker::is_excluded_path(file_notify_info const& info)
{
	return false;
}

SAIGON_NAMESPACE_END