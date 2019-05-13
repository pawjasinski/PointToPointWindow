#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "About", "Created by Pawel Jasinski", QMessageBox::Ok, QMessageBox::Ok);
}

void MainWindow::on_actionexit_triggered()
{
    QMessageBox::StandardButton reply = QMessageBox::warning(this, "Warning", "Do you want exit without save changes?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (reply == QMessageBox::Yes) QApplication::quit();
}

void MainWindow::on_actionimport_Points_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if(! fileName.isEmpty() )
    {
        loadFile(fileName);
    }
}

void MainWindow::on_actionimport_Control_Points_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if(! fileName.isEmpty() )
    {
        loadFile(fileName);
    }
}

void MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if(! file.open(QFile::ReadOnly | QFile::Text) )
    {
        QMessageBox::warning(this, "Warning", "Cannot open the file: " + fileName + file.errorString());
        return;
    }
    QTextStream read(&file);
}
