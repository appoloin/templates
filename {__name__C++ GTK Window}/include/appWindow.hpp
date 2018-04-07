/*
    File Name   = appWindow
    Date        = 2018-4-6 22:38:11
    Author      = 
    Description =    
*/

#ifndef app_window__H
#define app_window__H

#include "logger.hpp"
#include <gtkmm.h>

class AppWindow: public Gtk::ApplicationWindow
{
    public:
        AppWindow(BaseObjectType* cobject,
                  const Glib::RefPtr<Gtk::Builder>& refBuilder);

        static AppWindow* create();
        
    protected:
        Glib::RefPtr<Gtk::Builder> m_refBuilder;
};


#endif /* app_window__H */
