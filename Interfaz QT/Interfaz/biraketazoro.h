#ifndef BIRAKETAZORO_H
#define BIRAKETAZORO_H

#include <QMainWindow>
//#include "mainwindow.h"

namespace Ui {
class Biraketazoro;
}

class Biraketazoro : public QMainWindow
{
    Q_OBJECT

public:
    explicit Biraketazoro(QWidget *parent = 0);
    ~Biraketazoro();

private slots:

    void on_adosButton_clicked();

    void on_abiaduraAldatzailea_valueChanged(int arg1);

    void on_hasiButton_clicked();

    void on_pausaButton_clicked();

    void on_stopButton_clicked();

    void on_atzeraButton_clicked();

    void on_berrabiaraziButton_clicked();

    void on_actionManeiua_triggered();

    void on_actionKontrolak_triggered();

    void on_actionAbiadura_aukeraketa_triggered();

public slots:

    void showNagusia();

private:
    Ui::Biraketazoro *ui;

protected:

    virtual void keyPressEvent( QKeyEvent *event);

};

#endif // BIRAKETAZORO_H
