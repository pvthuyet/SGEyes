// SGEye.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "the_app.hpp"

int main()
{
    namespace sg = saigon;
    sg::the_app::get_instance().start();
}