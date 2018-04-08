/*
    File Name   = mainWindow.h
    Date        = 2018-4-8 12:50:23
    Author      = 
    Description =    
*/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "logger.hpp"
#include <QMainWindow>
#include <QCloseEvent>
#include "ui_mainWindow.h"



namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow 
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    protected:
        void closeEvent(QCloseEvent *event) override;
    
    private slots:
        void actionAbout();

    private:
        Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
