// SGEye.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "the_app.hpp"
#include "spdlog_header.h"

int main()
{
    namespace sg = saigon;
    // Initialize logger
    sg::initialze();

    // start app
    sg::the_app::get_instance().start();
    return 0;
}