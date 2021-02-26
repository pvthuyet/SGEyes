module;

#include "defines.h"
#include "fmt/core.h"

module SGEye.TheApp;

SAIGON_NAMESPACE_BEGIN

TheApp& TheApp::getInst()
{
	static TheApp app;
	return app;
}

void TheApp::start()
{
	fmt::print("Hello world!");
}

SAIGON_NAMESPACE_END