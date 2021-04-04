// SGEye.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vld.h>
#include "the_app.hpp"
#include "logger.hpp"
#include "logger_define.hpp"
#include <exception>

int main(int argc, char* argv[])
{
    namespace sg = saigon;
    try {
        // Initialize logger
        sg::logger::get_instance();

        int* x = new int(1);

        // start app
        sg::the_app::get_instance().start();
    }
    catch (std::exception const& ex) {
        SPDLOG_ERROR(ex.what());
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}