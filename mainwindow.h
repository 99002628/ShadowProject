#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_OkButtonClicked();
    void on_NextBtnClicked();
    void on_BackBtnClicked();
    void on_LoadBtnClicked();
    void on_DisplayBtnClicked();
private:
    Ui::MainWindow *ui;

 QMessageBox *messageBox;

};

#endif // MAINWINDOW_H
