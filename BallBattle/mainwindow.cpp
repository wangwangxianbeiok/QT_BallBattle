#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "battlefield.h"
#include "config.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(INITWIDTH,INITHEIGHT);
    connect(ui->start,QPushButton::pressed,this,[=]{
                int i = 0;
            });
    connect(ui->start,QPushButton::released,this,[=]{
                auto battlefield = new Battlefield;
                this->hide();
                battlefield->show();
            });
}

MainWindow::~MainWindow()
{
    delete ui;
}
