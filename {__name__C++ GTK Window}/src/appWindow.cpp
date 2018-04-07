/*
    File Name   = appWindow
    Date        = 2018-4-6 22:44:31
    Author      = 
    Description =    
*/

#include "appWindow.hpp"
#include <exception>

AppWindow::AppWindow(BaseObjectType* cobject,const Glib::RefPtr<Gtk::Builder>& refBuilder)
                        : Gtk::ApplicationWindow(cobject),
                        m_refBuilder(refBuilder)
{
    LOG_DEBUG("STARTED AppWindow Contructor");
}


AppWindow* AppWindow::create()
{
    LOG_DEBUG("STARTED AppWindow create");
    // Load the Builder file and instantiate its widgets.
    auto refBuilder = Gtk::Builder::create_from_file("res/gui.glade");

    AppWindow* window = nullptr;
    refBuilder->get_widget_derived("appwindow", window);
    if (!window)
        throw std::runtime_error("No \"app_window\" object in gui.glade");

    LOG_DEBUG("END AppWindow create");
    return window;
}