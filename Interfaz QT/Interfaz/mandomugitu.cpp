#include "mandomugitu.h"
#include "ui_mandomugitu.h"

//#include <stdio.h>
//#include <stdlib.h>
#include "mainwindow.h"


#include <QDebug>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPoint>
#include <QCursor>
#include <QMessageBox>
//#include <fstream>


extern char tekla;
//Stop botoia sakatu den egiaztatzeko aldagaia
extern bool stopBai,hasiBai;

Mandomugitu::Mandomugitu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mandomugitu)
{
    ui->setupUi(this);
    //Menua erakustean, botoiak sakatu diren egiaztatzeko aldagaiak "false"-rekin hasieratu
    stopBai = false;
    hasiBai = false;
    ui->hasiButton->setToolTip("Play!");
    ui->pausaButton->setToolTip("Pause!");
    ui->stopButton->setToolTip("Stop!");
    ui->berrabiaraziButton->setToolTip("Berrabiarazi!");
    ui->atzeraButton->setToolTip("Atzera!");
}

Mandomugitu::~Mandomugitu()
{
    delete ui;

}

//Tekla bat sakatzean sortzen den ekintza
void Mandomugitu::keyPressEvent( QKeyEvent * event )
{
    // X eta Y ardatzetako posizioa bertan gordeko dira
    int posx,posy;
    QCursor pos;
    //X eta Y ardatzeko posizioa lortzeko x() eta y() funtzioak erabiltzeko objektuaren erazagupena
    QPoint posiz;
    //rfcomm0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //fputc funtzioan char motakoak bidali behar direnez posx eta posy aldagaien 'karaktere' motako aldagaiak
    char cposx,cposy;
    //idatzitako teklaren kodea jasotzen da
    const int botoi = event->key();
        //Tekla bakoitzaren kodearekin konparatzen da, eta koinziditzen badute, letra hori bidaltzen zaio pololuri
        switch (botoi)
        {

            //A letraren kodea,Wiimote-ko A botoia sakatzen dagoen bitartean kurtsorearen posizioak bidaliko zaizkio robotaren programari
            case Qt::Key_A :
            //posiz objektuan pos() funtzioak itzultzen dituen pantailako uneko x eta y balioak gordeko dira
            posiz = QCursor::pos();
            //Pantailak har dezakeen X eta Y posiziorik altuena 1365 eta 767 direnez da,eta balio hauek handiegiak direnez 13,65 eta 7,67 balioarengatik zatituko da
            //Horrela  posx eta posy-k izango duten baliorik handiena 100 izango da
            //posx aldagaiean posiz objektuko x posizioa esleituko da
            posx = posiz.x()/13.65;
            //posy aldagaiean posiz objektuko y posizioa esleituko da
            posy = posiz.y()/7.67;
            //Robotaren programari bidaliko zaion 'a' tekla esleitzen da
            tekla = 'a';
            //fputc erabili ahal izateko egiten den (char) castinga cposx eta cposy-en esleituz
            cposx =(char)posx;
            cposy =(char)posy;
             //'a' tekla bidaliko zaio robotaren programari Wiimote-ko 'A' botoia sakatu dela jakinarazteko
            fputc(tekla, portua);
            //Kurtsorearen uneko x eta y posizioak bidaliko zaizkio robotaren programari RFCOMM0 portutik
            fputc(cposy, portua);
            fputc(cposx, portua);
            break;
            //B tekla bidaliko zaio robotak frenatzea nahi dugunean
            case Qt::Key_B :
            tekla = 'b';
            fputc(tekla, portua);
            break;
            //Pantailaren posizioa kalibratzen da
            case Qt::Key_1:
            pos.setPos(683,384);
            break;

        }

         fclose(portua);
}

//Play botoia sakatzen bada sortzen den ekintza
void Mandomugitu::on_hasiButton_clicked()
{
        //RFCOMM0 portua ireki
        FILE * portua = fopen ("/dev/rfcomm0", "w");
        QMessageBox infoBox;
        //Kurtsorearen posizioa aldatzeko erabiliko den objektua
        QCursor pos;
        infoBox.information(this,"Kalibratua","Wii-ko mandoa ondo kalibratua dago, aurrera!");
        tekla='h';
        hasiBai = true;
        stopBai = false;
        //Kurtsorea pantailaren erdian kokatuko da
        pos.setPos(683,384);
        //Robotaren programari bidaltzeko zaio h tekla adierazteko robotaren mugimendu funtzionamentua prest dagoela
        fputc(tekla,portua);
        fclose(portua);

}

void Mandomugitu::on_pausaButton_clicked()
{
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    tekla='p';
    fputc(tekla,portua);
    fclose(portua);
}

//Pause botoia sakatzen denean sortzen den ekintza
void Mandomugitu::on_stopButton_clicked()
{
    //RFCOMM0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //'s'(stop) tekla bidaltzen zaio robotaren programari RFCOMM0 portutik
    tekla='s';
    stopBai = true;
    fputc(tekla,portua);
    //RFCOMM0 portua ixten da
    fclose(portua);
    stopBai = true;

}

//Menu nagusira bueltatzeko 'Atzera' botoia sakatzen denean sortzen den ekintza
void Mandomugitu::on_atzeraButton_clicked()
{
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    tekla='o';
    fputc(tekla,portua);
    fclose(portua);

}

void Mandomugitu::on_berrabiaraziButton_clicked()
{
    //Aukera berrabiarazteko dagoen botoia sakatzean sortzen den ekintza
    //RFCOMM0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //robotaren programari 'Wiimote-a mugituz' modua aukeratzeko aldagaia
    tekla='1';
    //'1' zenbakia bidaliko zaio robotaren programari 'mugitu_mandoarekin' funtzioa martxan jarri dadin
    fputc(tekla,portua);
    //RFCOMM0 portua ixten da
    fclose(portua);
}

//Menu nagusia erakusteko prozedura
void Mandomugitu::showNagusia()
{

    QMessageBox mezuWarning;
     //Hasi botoia sakatu bada, baina Stop botoia ez, menu nagusira joateko 'Stop' botoia sakatu beharko da
    if(hasiBai == true && stopBai == false)
    {
        mezuWarning.warning(this,"Abisua","ADI! Ez duzu STOP botoia sakatu,STOP sakatu atzera egin ahal izateko");
    }
    //Hasi ez bada sakatu 'atzera' sakatuta menu nagusia joango da
    else
    {
        MainWindow *mainwindow = new MainWindow();
        this->hide();
        mainwindow->show();

    }

}

//Menu hedagarriko Maneiuari click eginez gero
void Mandomugitu::on_actionManeiua_triggered()
{
    QMessageBox maneiuaBox;
    //Maneiuaren azalpen mezua agertu
    maneiuaBox.setText("5 botoi dituzu menu honetan: Play,Pause,Stop,Berrabiarazi eta Atzera.\n\n Jolasten hasteko 'Play' botoiari eman behar diozu. 'Atzera' botoiari emateko aukera duzu eta menu nagusira joango da. 'Play' botoiari eman ondoren robota prest egongo da martxan jartzeko, aldiz momenturen batean robota geratu nahi baduzu aldi baterako, 'Pause'' botoiari emango diozu,eta berriro robota martxan jartzeko kurtsoreak erabiliko dituzu.\n\n Azkenik robota guztiz geratu nahi baduzu 'Stop' botoiari emango diozu, behin botoi hau sakaturik ezingo duzu robota mugitu 'Berrabiarazi' botoia sakatu ezean. 'Berrabiarazi' botoia sakatzean, dena hasieratuko da eta aukera izango duzu 'Play' botoiari sakatuta robota berriro martxan jartzeko.");
    maneiuaBox.exec();
}

//Menu hedagarriko Kontrola-ri click eginez gero
void Mandomugitu::on_actionKontrolak_triggered()
{
    QMessageBox kontrolakBox;
    //Kontrolen azalpen mezua agertu
    kontrolakBox.setText("Hau da seguraski aplikazioaren funtzionalitaterik politena. Robota Wiimote-ko norabide botoiei sakatu gabe mugitzeko aukera eskaintzen baitu.Robota aurrera/atzera/eskuin/ezkerrerantz ibili dadin, Wiimote-ko ‘A’ botoia sakatzen egon beharko da, berau sakatu ezean robota ez baita mugituko.Robota aurrerantz edo atzerantz mugitu nahi bada, ‘A’ botoia sakatzen dugun bitartean Wiimote-a gorantz(aurrera) eta beherantz (atzera) mugitu beharko da. Kontuan hartu behar da mugitzen ari garen heinean abiadura areagotzen joango dela, bai aurrera bai atzerantzko kasuetan.Robotaren abiadura gutxiagotu nahi bada, Wiimote-ren atzean dagoen ‘B’ botoia sakatu beharko da. Robota eskuin edo ezkerrerantz mugitu nahi bada, ‘A’ botoia sakatzen dugun bitartean ezker edo eskuinerantz mugitu beharko dugu Wiimote-a.");
    kontrolakBox.exec();
}
