/*
    File Name   = mainWindow
    Date        = 2018-4-6 22:38:11
    Author      = 
    Description =    
*/

#ifndef main_window__H
#define main_window__H

#include "logger.hpp"
#include <gtkmm.h>

class mainWindow : public Gtk::Window
{
    public:
        //constructor
        mainWindow(BaseObjectType* cobject, 
                    const Glib::RefPtr<Gtk::Builder>& refGlade);
    protected:
        Glib::RefPtr<Gtk::Builder> builder;
        Gtk::Button *btnOk;
        Gtk::Button *btnCancel;
        Gtk::Label *lblNotice;

        //on close
        virtual bool on_delete_event (GdkEventAny* );

        //signal handlers
        void on_ok_button_clicked();
        void on_cancel_button_clicked(); 
};


#endif /* main_window */
