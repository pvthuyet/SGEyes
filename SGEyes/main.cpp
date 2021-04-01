// SGEye.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vld.h>
#include "the_app.hpp"
#include "logger.hpp"

int main()
{
    namespace sg = saigon;
    // Initialize logger
    sg::logger::get_instance();

    int* x = new int(1);

    // start app
    sg::the_app::get_instance().start();
    return 0;
}