/*
    File Name   = {__name__}
    Date        = {__date__}
    Author      = 
    Description =    
*/


#include <iostream>
#include <string>
#include "logger.hpp"

int main(int argc, char *argv[]) 
{
    if (argc > 1) //start logging
    {
        Logger::initFromConfig(argv[1]);
    } 
    else 
    {
        Logger::init();
    }

    LOG_DEBUG("STARTED main");
	std::cout << "Hello Easy C++ project!" << std::endl;
}

