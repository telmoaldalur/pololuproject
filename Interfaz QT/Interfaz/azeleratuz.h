#ifndef AZELERATUZ_H
#define AZELERATUZ_H

#include <QMainWindow>


namespace Ui {
class Azeleratuz;
}

class Azeleratuz : public QMainWindow
{
    Q_OBJECT

public:
    explicit Azeleratuz(QWidget *parent = 0);
    ~Azeleratuz();

private:
    Ui::Azeleratuz *ui;
    //MainWindow mainwindow;

protected:

    virtual void keyPressEvent( QKeyEvent *event);

private slots:
    void on_hasiButton_clicked();
    void on_pausaButton_clicked();
    void on_stopButton_clicked();
    void on_berrabiaraziButton_clicked();
    void on_atzeraButton_clicked();

    void on_actionManeiua_triggered();

    void on_actionKontrolak_triggered();

public slots:

    void showNagusia();
    //void showAzalpena();


};




#endif // AZELERATUZ_H
