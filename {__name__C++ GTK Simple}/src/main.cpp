/*
    File Name   = gtk2
    Date        = 2018-4-5 19:46:37
    Author      = 
    Description =    
*/

#include <iostream>
#include <gtkmm.h>
#include "logger.hpp"
#include "mainWindow.hpp"


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

        // Initialize gtkmm
        Gtk::Main app(argc, argv);
	           
        // Create the window
	    auto builder = Gtk::Builder::create_from_file("res/gui.glade");
        mainWindow *pMainWindow = nullptr;
        builder->get_widget_derived("mainWin", pMainWindow);
        app.run(*pMainWindow);
        
        delete pMainWindow;
        LOG_DEBUG("END main");
        return 0;
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
