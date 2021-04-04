#include "the_app.hpp"
#include "file_activity/directory_watcher_mgr.hpp"
#include <string>
#include <thread>

#ifdef IS_WINDOWS
#include <Windows.h>

constexpr unsigned long  NOTIFY_CHANGE_FLAG = (FILE_NOTIFY_CHANGE_FILE_NAME
	| FILE_NOTIFY_CHANGE_LAST_WRITE
	| FILE_NOTIFY_CHANGE_DIR_NAME
	| FILE_NOTIFY_CHANGE_ATTRIBUTES
	| FILE_NOTIFY_CHANGE_SECURITY);

#else
constexpr unsigned long  NOTIFY_CHANGE_FLAG = 0;
#endif

SAIGON_NAMESPACE_BEGIN

the_app& the_app::get_instance()
{
	static the_app app;
	return app;
}

std::string say_hello() 
{
	std::string msg;
#ifdef IS_WINDOWS
	msg = std::string("Hello from Windows!");
#elif IS_LINUX
	msg = std::string("Hello from Linux!");
#elif IS_MACOS
	msg = std::string("Hello from macOS!");
#else
	msg = std::string("Hello from an unknown system!");
#endif

	msg += " - ";
#ifdef IS_INTEL_CXX_COMPILER
	// only compiled when Intel compiler is selected
	// such compiler will not compile the other branches
	msg += std::string("Hello Intel compiler!");
#elif IS_GNU_CXX_COMPILER
	// only compiled when GNU compiler is selected
	// such compiler will not compile the other branches
	msg += std::string("Hello GNU compiler!");
#elif IS_PGI_CXX_COMPILER
	// etc.
	msg += std::string("Hello PGI compiler!");
#elif IS_XL_CXX_COMPILER
	msg += std::string("Hello XL compiler!");
#elif IS_MSVC_CXX_COMPILER
	msg += std::string("Hello MSVC compiler!");
#else
	msg += std::string("Hello unknown compiler - have we met before?");
#endif
	return msg;
}

void the_app::start()
{
	//auto msg = say_hello();
	directory_watcher_mgr mgr{};
	mgr.start(NOTIFY_CHANGE_FLAG);
	std::this_thread::sleep_for(std::chrono::seconds(10));
}

SAIGON_NAMESPACE_END