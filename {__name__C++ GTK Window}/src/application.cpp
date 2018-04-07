/*
    File Name   = application
    Date        = 2018-4-7 18:18:17
    Author      = 
    Description =    
*/


#include "application.hpp"
#include "appWindow.hpp"


Application::Application()
            : Gtk::Application("new.application", Gio::APPLICATION_HANDLES_OPEN)
{
    LOG_DEBUG("STARTED Application constructor");
}



Glib::RefPtr<Application> Application::create()
{
    LOG_DEBUG("STARTED Application create");

    return Glib::RefPtr<Application>(new Application());
}



AppWindow* Application::create_appwindow()
{
    LOG_DEBUG("STARTED Application creat_appwindow");
    auto appwindow = AppWindow::create();

    // Make sure that the application runs for as long this window is still open.
    add_window(*appwindow);

    // Gtk::Application::add_window() connects a signal handler to the window's
    // signal_hide(). That handler removes the window from the application.
    // If it's the last window to be removed, the application stops running.
    // Gtk::Window::set_application() does not connect a signal handler, but is
    // otherwise equivalent to Gtk::Application::add_window().

    // Delete the window when it is hidden.
    appwindow->signal_hide().connect(sigc::bind<Gtk::Window*>(sigc::mem_fun(*this,
                                            &Application::on_hide_window), appwindow));

    LOG_DEBUG("END Application creat_appwindow");
    return appwindow;
}



void Application::on_startup()
{
    LOG_DEBUG("STARTED Application on_startup");
    // Call the base class's implementation.
    Gtk::Application::on_startup();

    AppWindow* appwindow = nullptr;
    auto windows = get_windows();
    if (windows.size() > 0)
        appwindow = dynamic_cast<AppWindow*>(windows[0]);

    try
    {
        if (!appwindow)
        appwindow = create_appwindow();
        
        appwindow->present();
    }
    catch (const Glib::Error& ex)
    {
        LOG_ERROR("Application::on_open(): " << ex.what());
    }
    catch (const std::exception& ex)
    {
        LOG_ERROR("Application::on_open(): " << ex.what());
    }

    // Add actions and keyboard accelerators for the application menu.
    add_action("quit", sigc::mem_fun(*this, &Application::on_action_quit));
    set_accel_for_action("app.quit", "<Ctrl>Q");

    LOG_DEBUG("END Application on_startup");
}



void Application::on_activate()
{
    LOG_DEBUG("START Application on_activate");
    try
    {
        // The application has been started, so let's show a window.
        auto appwindow = create_appwindow();
        appwindow->present();
    }
    // If create_appwindow() throws an exception (perhaps from Gtk::Builder),
    // no window has been created, no window has been added to the application,
    // and therefore the application will stop running.
    catch (const Glib::Error& ex)
    {
        LOG_ERROR("ExampleApplication::on_activate(): " << ex.what());
    }
    catch (const std::exception& ex)
    {
        LOG_ERROR("ExampleApplication::on_activate(): " << ex.what());
    }
    LOG_DEBUG("END Application on_activate");
}



void Application::on_action_quit()
{
    LOG_DEBUG("STARTED Application on_action_quit");
    // but it's a crude way of ending the program. The window is not removed
    // from the application. Neither the window's nor the application's
    // destructors will be called, because there will be remaining reference
    // Gio::Application::quit() will make Gio::Application::run() return,
    // counts in both of them. If we want the destructors to be called, we
    // must remove the window from the application. One way of doing this
    // is to hide the window. See comment in create_appwindow().
    auto windows = get_windows();
    for (auto window : windows)
        window->hide();

    // Not really necessary, when Gtk::Widget::hide() is called, unless
    // Gio::Application::hold() has been called without a corresponding call
    // to Gio::Application::release().
    quit();
    LOG_DEBUG("END Application on_action_quit");
}



void Application::on_hide_window(Gtk::Window* window)
{
    LOG_DEBUG("STARTED Application on_hide_window");
    delete window;
}