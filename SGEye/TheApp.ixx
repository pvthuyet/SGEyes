module;

#include "defines.h"

export module SGEye.TheApp;

SAIGON_NAMESPACE_BEGIN
export class TheApp
{
public:
	static TheApp& getInst();
	void start();

private:
	TheApp() = default;
};

SAIGON_NAMESPACE_END