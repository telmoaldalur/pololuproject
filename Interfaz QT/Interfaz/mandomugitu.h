#ifndef MANDOMUGITU_H
#define MANDOMUGITU_H

#include <QMainWindow>


namespace Ui {
class Mandomugitu;
}

class Mandomugitu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mandomugitu(QWidget *parent = 0);
    ~Mandomugitu();

private:
    Ui::Mandomugitu *ui;

protected:

    virtual void keyPressEvent( QKeyEvent *event);

private slots:
    void on_hasiButton_clicked();

    void on_pausaButton_clicked();

    void on_stopButton_clicked();

    void on_atzeraButton_clicked();

    void on_actionManeiua_triggered();

    void on_actionKontrolak_triggered();

    void on_berrabiaraziButton_clicked();

public slots:

    void showNagusia();
    //void showAzalpena();
};

#endif // MANDOMUGITU_H


