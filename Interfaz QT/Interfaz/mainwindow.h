#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "biraketazoro.h"
#include "mandomugitu.h"
#include "biraketanormal.h"
#include "azeleratuz.h"


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




    void on_mandoaMugituzButton_clicked();

    void on_biraketaZoroaButton_clicked();

    void on_biraketaNormalButton_clicked();

    void on_azeleratuzButton_clicked();

    void on_bukatuButton_clicked();

private:
    Ui::MainWindow *ui;
    Biraketazoro biraketazoro;
    Mandomugitu mandomugitu;
    Biraketanormal biraketanormal;
    Azeleratuz azeleratuz;

protected:



};

#endif // MAINWINDOW_H
