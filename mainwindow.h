#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadFile(const QString &fileName);

private slots:
    void on_actionAbout_triggered();
    void on_actionexit_triggered();

    void on_actionimport_Points_triggered();

    void on_actionimport_Control_Points_triggered();

private:
    Ui::MainWindow *ui;
    QString points;
    QString controlPoints;

};

#endif // MAINWINDOW_H
