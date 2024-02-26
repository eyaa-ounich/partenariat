#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "partenariat.h"
#include "partenaire.h"
#include"QMessageBox"
#include"QDate"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    hide();

        partenariat partenaire ;
        partenaire.setModal(true) ;
        partenaire.exec() ;

}
