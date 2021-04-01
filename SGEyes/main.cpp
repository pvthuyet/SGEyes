// SGEye.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "the_app.hpp"
#include "spdlog_header.h"
#include "vld.h"

int main()
{
    namespace sg = saigon;
    // Initialize logger
    sg::initialze();
    int* x = new int(1);

    // start app
    sg::the_app::get_instance().start();
    return 0;
}