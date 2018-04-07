/*
    File Name   = mainWindow
    Date        = 2018-4-6 22:44:31
    Author      = 
    Description =    
*/

#include "mainWindow.hpp"

mainWindow::mainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
	                Gtk::Window(cobject), builder(refGlade)
{

    LOG_DEBUG("START mainWindow Constructor");

    builder->get_widget("btnOk", btnOk);
    builder->get_widget("btnCancel", btnCancel);
    builder->get_widget("lblNotice",lblNotice);

    btnOk->signal_clicked().connect(sigc::mem_fun(*this, &mainWindow::on_ok_button_clicked));
    btnCancel->signal_clicked().connect(sigc::mem_fun(*this, &mainWindow::on_cancel_button_clicked));

    LOG_DEBUG("END mainWindow Constructor");
}


bool mainWindow::on_delete_event(GdkEventAny* event) 
{ 
    LOG_DEBUG("START mainWindow onExitClicked");
    LOG_DEBUG("END mainWindow onExitClicked");
    return false;  //use default handling
}

void mainWindow::on_ok_button_clicked()
{
    LOG_DEBUG("START mainWindow on_ok_button_clicked");

	lblNotice->set_text("OK clicked");

    LOG_DEBUG("END mainWindow on_ok_button_clicked");
}

void mainWindow::on_cancel_button_clicked()
{
    LOG_DEBUG("START mainWindow on_cancel_button_clicked");

	lblNotice->set_text("Cancel clicked");

    LOG_DEBUG("END mainWindow on_cancel_button_clicked");
}
