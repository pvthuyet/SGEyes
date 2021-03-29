#ifndef SGEYE_THE_APP__
#define SGEYE_THE_APP__

#pragma once
#include "define.h"

SAIGON_NAMESPACE_BEGIN
class the_app
{
public:
	static the_app& get_instance();
	void start();

private:
	the_app() = default;
};

SAIGON_NAMESPACE_END

#endif // !SGEYE_THE_APP__