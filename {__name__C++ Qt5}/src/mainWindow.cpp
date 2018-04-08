/*
    File Name   = mainWindow.cpp
    Date        = 2018-4-8 12:50:23
    Author      = 
    Description =    
*/

#include "mainWindow.hpp"


MainWindow::MainWindow(QWidget *parent) :
            QMainWindow(parent),
            ui(new Ui::MainWindow)
{
    LOG_DEBUG("STARTED MainWindow Constructor");
   
    ui->setupUi(this);  

    setWindowTitle(tr("Hello World")); //Fixme Tile needs to be changed

    LOG_DEBUG("END MainWindow Constructor");
}

MainWindow::~MainWindow()
{
    LOG_DEBUG("STARTED MainWindow destructor");
    
    delete ui;

    LOG_DEBUG("END MainWindow destructor");

}

void MainWindow::closeEvent(QCloseEvent *closeEvent)
{
    LOG_DEBUG("STARTED MainWindow closeEvent");

    closeEvent->accept();

    LOG_DEBUG("END MainWindow closeEvent");   
}



void MainWindow::actionAbout()
{
    LOG_DEBUG("STARTED MainWindow actionAbout");
    
    statusBar()->showMessage(tr("Ready"));

    LOG_DEBUG("END MainWindow actionAbout");   
}