/*
    File Name   = gtk2
    Date        = 2018-4-5 19:46:37
    Author      = 
    Description =    
*/

#include <iostream>
#include <gtkmm.h>
#include "logger.hpp"
#include "application.hpp"


int main(int argc, char *argv[])
{
    try
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

        auto app = Application::create();

        // Start the application, showing the initial window,
        // and opening extra views for any files that it is asked to open,
        // for instance as a command-line parameter.
        // run() will return when the last window has been closed.
        return app->run(argc, argv);
    }
    catch(const Glib::Error& ex)
    {   //GTKMM excpetions through here
        LOG_ERROR ("GlibError: " << ex.what());
        return 1;
    }
    catch(const std::exception& ex)  
    {   //Everything else through here
        LOG_ERROR ("StandardError: " << ex.what());
        return 1;
    }
    catch(...)
    {   //your guess is as good as mine
        LOG_ERROR ("DefaultError: Catch all");
        return 1;
    }
}
