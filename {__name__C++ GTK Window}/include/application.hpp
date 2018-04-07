/*
    File Name   = application
    Date        = 2018-4-7 18:12:04
    Author      = 
    Description =    
*/

#ifndef application__H
#define application__H


#include <gtkmm.h>
#include "logger.hpp"

class AppWindow;

class Application: public Gtk::Application
{
    protected:
        Application();

    public:
        static Glib::RefPtr<Application> create();

    protected:
        // Override default signal handlers:
        void on_activate() override;
        void on_startup() override;
       
    private:
        AppWindow* create_appwindow();
        void on_hide_window(Gtk::Window* window);
        void on_action_quit();
};




#endif /* application */
