#ifndef SPDLOG_HEADER_H_
#define SPDLOG_HEADER_H_
#pragma once

#include "define.h"
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#define SPDLOG_DEBUG_ON
#define SPDLOG_TRACE_ON
#define SPDLOG_WCHAR_TO_UTF8_SUPPORT
#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

#define LOGENTER	SPDLOG_INFO("Enter {")
#define LOGEXIT		SPDLOG_INFO("Exit }")

SAIGON_NAMESPACE_BEGIN

static void initialze()
{
	spdlog::init_thread_pool(8192, 1);
	auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt >();
	auto rotating_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("logger.log", 1024 * 1024 * 10, 10);
	std::vector<spdlog::sink_ptr> sinks{ stdout_sink, rotating_sink };
	auto asynLog = std::make_shared<spdlog::async_logger>("saigon", sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block);
	asynLog->set_pattern("[%Y-%m-%d_%H:%M:%S %e] [%^%l%$] [thread %t] [%!:%#] %v");
	spdlog::set_default_logger(asynLog);
	spdlog::flush_every(std::chrono::seconds(10));
#ifdef _DEBUG
	spdlog::set_level(spdlog::level::debug);
	spdlog::flush_on(spdlog::level::debug);
	spdlog::flush_every(std::chrono::seconds(1));
#endif // _DEBUG
}

SAIGON_NAMESPACE_END

#endif // !SPDLOG_HEADER_H_