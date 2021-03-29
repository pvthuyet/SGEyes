#include "the_app.hpp"

#include "fmt/core.h"

SAIGON_NAMESPACE_BEGIN

the_app& the_app::get_instance()
{
	static the_app app;
	return app;
}

void the_app::start()
{
	fmt::print("Hello world!");
}

SAIGON_NAMESPACE_END