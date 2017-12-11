#include "azeleratuz.h"
#include "ui_azeleratuz.h"
#include "mainwindow.h"

#include <QKeyEvent>
#include <QMessageBox>

//Kanpoko aldagaiak
extern char tekla;
extern char aukera;
//Stop eta Play botoiak sakatu diren egiaztatzeko aldagaia
extern bool stopBai,hasiBai;

//Aldagai globalak
int abiaduraAz=0;
char hasi;



Azeleratuz::Azeleratuz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Azeleratuz)
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

Azeleratuz::~Azeleratuz()
{
    delete ui;
}

//Teklatuko ekintzak
void Azeleratuz::keyPressEvent( QKeyEvent * event )
{
    QMessageBox abiaduraMaxAbisua;
    //'Play' botoiari sakatu bazaio
    if(hasiBai== true)
    {

    //RFCOMM0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //idatzitako teklaren kodea jasotzen da
    const int botoi = event->key();
        //Abiadura muga ez bada gainditu
        if(abiaduraAz < 100)
        {
            switch (botoi)
            {
            //Tekla bakoitzaren kodearekin konparatzen da, eta koinziditzen badute, letra hori bidaltzen zaio pololuri

                //U letraren kodea
                case Qt::Key_U :
                    tekla='u';
                    //'u'(gora) tekla bidaltzen zaio robotaren programari RFCOMM0 portutik
                    fputc(tekla, portua);
                    //Lcd-an agertuko den abiadura markagailua inkrementatu
                    abiaduraAz++;
                    //Inkrementatu ahala, abiadura erakutsi
                    ui->lcdNumber->display(abiaduraAz);
                    break;
                //D letraren kodea
                case Qt::Key_D :
                    tekla='d';
                    //'d'(behera) tekla bidaltzen zaio robotaren programari RFCOMM0 portutik
                    fputc(tekla, portua);
                    //Lcd-an agertuko den abiadura markagailua inkrementatu
                    abiaduraAz++;
                    //Inkrementatu ahala, abiadura erakutsi
                    ui->lcdNumber->display(abiaduraAz);
                    break;
                //L letraren kodea
                case Qt::Key_L :
                    tekla='l';
                    //'l'(ezkerretara) tekla bidaltzen zaio robotaren programari RFCOMM0 portutik
                    fputc(tekla, portua);
                    //Lcd-an agertuko den abiadura markagailua inkrementatu
                    abiaduraAz;
                    //Inkrementatu ahala, abiadura erakutsi
                    ui->lcdNumber->display(abiaduraAz);
                    break;
                //R letraren kodea
                case Qt::Key_R :
                    tekla='r';
                    //'r'(eskuinetara) tekla bidaltzen zaio robotaren programari RFCOMM0 portutik
                    fputc(tekla, portua);
                    //Lcd-an agertuko den abiadura markagailua inkrementatu
                    abiaduraAz;
                    //Inkrementatu ahala, abiadura erakutsi
                    ui->lcdNumber->display(abiaduraAz);
                    break;
                case Qt::Key_B :
                    //abiadura 0 baino handiago bada, abiadura dekrementatu
                    if(abiaduraAz>=0)
                    {
                        tekla='b';
                        //'b'(balaztatu) tekla bidaltzen zaio robotaren programari RFCOMM0 portutik
                        fputc(tekla, portua);
                        //Lcd-an agertuko den abiadura markagailua dekrementatu
                        abiaduraAz--;
                        //Inkrementatu ahala, abiadura erakutsi
                        ui->lcdNumber->display(abiaduraAz);
                    }
                    break;
            }
        }
        //100-eko abiadura muga gainditzen bada:
        else
        {
            //Mezua agertuko da balaztatzeko esanaz
            abiaduraMaxAbisua.warning(this,"Azkarregi!","Abiadura muga gainditu duzu,balazta ezazu");
            abiaduraAz--;
        }
        //Ekintzak onartzen direla adierazteko
        event->accept();
        //RFCOMM0 portua ixten da
        fclose(portua);
    }

}


//Play botoia sakatzen bada sortzen den ekintza
void Azeleratuz::on_hasiButton_clicked()
{
    //RFCOMM0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //Mezuen kutxaren erazagupena
    QMessageBox infoBox;

    //tekla aldagaiari 'h' esleitzen zaio
    tekla='h';
    //Mezua agertuko da prest dagoela esanaz
    infoBox.information(this,"PREST!","Dena prest dago,aurrera!");
    //'Play' botoia sakatu dela adierazten da aldagaiean
    hasiBai = true;
    stopBai = false;
    //'h'(hasi) tekla bidaltzen zaio robotaren programari RFCOMM0 portutik
    fputc(tekla,portua);
    //RFCOMM0 portua ixten da
    fclose(portua);
}

//Pause botoia sakatzen denean sortzen den ekintza
void Azeleratuz::on_pausaButton_clicked()
{
    //RFCOMM0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //tekla aldagaiari 'p' esleitzen zaio
    tekla='p';
    //'p'(pause) tekla bidaltzen zaio robotaren programari RFCOMM0 portutik
    fputc(tekla,portua);
    //RFCOMM0 portua ixten da
    fclose(portua);
}

//Stop botoia sakatzen denean sortzen den ekintza
void Azeleratuz::on_stopButton_clicked()
{
    //RFCOMM0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //tekla aldagaiari 's' esleitzen zaio
    tekla = 's';
    hasiBai = false;
    fputc(tekla,portua);
    //RFCOMM0 portua ixten da
    fclose(portua);
    stopBai = true;
}

//Aukera berrabiarazteko dagoen botoia sakatzean sortzen den ekintza
void Azeleratuz::on_berrabiaraziButton_clicked()
{
    //RFCOMM0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //robotaren programari 'Azeleratuz' modua aukeratzeko aldagaia
    tekla='4';
    //'4' zenbakia bidaliko zaio robotaren programari 'Azeleratuz' funtzioa martxan jarri dadin
    fputc(tekla,portua);
    //RFCOMM0 portua ixten da
    fclose(portua);
    //LCD-an agertuko den abiadura 0-ra hasieratu
    abiaduraAz = 0;
    //LCD-an abiadura agertzeko funtzioa
    ui->lcdNumber->display(abiaduraAz);
}

//Menu nagusira bueltatzeko 'Atzera' botoia sakatzen denean sortzen den ekintza
void Azeleratuz::on_atzeraButton_clicked()
{

    //RFCOMM0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //robotaren programari atzera botoia sakatu dela komunikatzeko erabiliko den aldagaia
    tekla='a';
    //LCD-an agertuko den abiadura 0-ra hasieratu
    abiaduraAz = 0;
    //'a' tekla bidaliko zaio robotaren programari 'Atzera' botoia sakatu dela jakinarazteko
    fputc(tekla,portua);
    //RFCOMM0 portua ixten da
    fclose(portua);


}

//Menu nagusia erakusteko prozedura
void Azeleratuz::showNagusia()
{
    //Abisuaren MsgBox erazagupena
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
void Azeleratuz::on_actionManeiua_triggered()
{
    QMessageBox maneiuaBox;
    maneiuaBox.setText("5 botoi dituzu menu honetan: Play,Pause,Stop,Berrabiarazi eta Atzera.\n\n Jolasten hasteko 'Play' botoiari eman behar diozu. 'Atzera' botoiari emateko aukera duzu eta menu nagusira joango da. 'Play' botoiari eman ondoren robota prest egongo da martxan jartzeko, aldiz momenturen batean robota geratu nahi baduzu aldi baterako, 'Pause'' botoiari emango diozu,eta berriro robota martxan jartzeko kurtsoreak erabiliko dituzu.\n\n Azkenik robota guztiz geratu nahi baduzu 'Stop' botoiari emango diozu, behin botoi hau sakaturik ezingo duzu robota mugitu 'Berrabiarazi' botoia sakatu ezean. 'Berrabiarazi' botoia sakatzean, dena hasieratuko da eta aukera izango duzu 'Play' botoiari sakatuta robota berriro martxan jartzeko.\n\n Berritasun moduan, abiadura erakusle bat dugu, robota doan abiadura adieraziko diguna");
    //Maneiuaren azalpen mezua agertu
    maneiuaBox.exec();
}

//Menu hedagarriko Kontrola-ri click eginez gero
void Azeleratuz::on_actionKontrolak_triggered()
{
    QMessageBox kontrolakBox;
    //Kontrolen azalpen mezua agertu
    kontrolakBox.setText("Robotaren kontrola Wiimote-ko norabide botoiekin(aurrera/atzera(ezker/eskuin),eta Wiimote-ko azpikaldean duzun 'B' botoiarekin burutuko duzu.\n\n Wiimote-ko norabide botoiekin robota 0 abiaduratik gora azeleratuz joango da, bertan duzun abiadura erakuslean ikusten den moduan. Robotaren abiadura gutxitu nahi izanez gero Wiimote-ko 'B' botoiari sakatuko diozu.");
    kontrolakBox.exec();
}
