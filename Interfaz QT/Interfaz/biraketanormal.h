#ifndef BIRAKETANORMAL_H
#define BIRAKETANORMAL_H

#include <QMainWindow>
//#include "azeleratuz.h"

namespace Ui {
class Biraketanormal;
}

class Biraketanormal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Biraketanormal(QWidget *parent = 0);
    ~Biraketanormal();

private:
    Ui::Biraketanormal *ui;
    //MainWindow mainwindow;

protected:

    virtual void keyPressEvent( QKeyEvent *event);

private slots:
    void on_hasiButton_clicked();
    void on_abiaduraAldatzailea_valueChanged(int arg1);

    void on_adosButton_clicked();
    void on_pausaButton_clicked();
    void on_stopButton_clicked();
    void on_atzeraButton_clicked();
    void on_berrabiaraziButton_clicked();

    void on_actionManeiua_triggered();

    void on_actionKontrolak_triggered();

    void on_actionAbiadura_aukeraketa_triggered();

public slots:

    void showNagusia();
    //void showAzalpena();
};



#endif // BIRAKETANORMAL_H
