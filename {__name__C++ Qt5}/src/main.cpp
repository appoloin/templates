/*
    File Name   = main
    Date        = 2018-4-8 12:50:23
    Author      = 
    Description =    
*/


#include <QApplication>
#include "mainWindow.hpp"
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

    Q_INIT_RESOURCE(resources);
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}