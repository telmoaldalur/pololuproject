#include "biraketanormal.h"
#include "ui_biraketanormal.h"
#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"





//Stop,Play,Ados botoia sakatu den egiaztatzeko aldagaia
extern bool stopBai,hasiBai,adosBai,abiadaldatuBai;
//Robotari bidaliko zaion tekla
char tekla;
//Abiadura aldatzaileak emandako abiadura gordetzeko
int abiadura;
//robotari bidali behar zaion abiadura
char abiaduraBidali;

Biraketanormal::Biraketanormal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Biraketanormal)
{
    ui->setupUi(this);
    //Menua erakustean, botoiak sakatu diren egiaztatzeko aldagaiak "false"-rekin hasieratu
    stopBai = false;
    hasiBai = false;
    adosBai = false;
    abiadaldatuBai = false;
    ui->hasiButton->setToolTip("Play!");
    ui->pausaButton->setToolTip("Pause!");
    ui->stopButton->setToolTip("Stop!");
    ui->berrabiaraziButton->setToolTip("Berrabiarazi!");
    ui->atzeraButton->setToolTip("Atzera!");
}

Biraketanormal::~Biraketanormal()
{
    delete ui;
}

//Teklatuko ekintzak
void Biraketanormal::keyPressEvent( QKeyEvent * event )
{
    //RFCOMM0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //idatzitako teklaren kodea jasotzen da
    const int botoi = event->key() ;
        //Tekla bakoitzaren kodearekin konparatzen da, eta koinziditzen badute, letra hori bidaltzen zaio pololuri
        switch (botoi)
        {
            //U letraren kodea
            case Qt::Key_U :
                tekla='u';
                //'u'(gora) tekla bidaltzen zaio robotaren programari RFCOMM0 portutik
                fputc(tekla, portua);
                break;
            //D letraren kodea
            case Qt::Key_D :
                tekla='d';
                //'d'(behera) tekla bidaltzen zaio robotaren programari RFCOMM0 portutik
                fputc(tekla, portua);
                break;
            //L letraren kodea
            case Qt::Key_L :
                tekla='l';
                //'l'(ezkerretara) tekla bidaltzen zaio robotaren programari RFCOMM0 portutik
                fputc(tekla, portua);
                break;
            //R letraren kodea
            case Qt::Key_R :
                tekla='r';
                //'r'(eskuinetara) tekla bidaltzen zaio robotaren programari RFCOMM0 portutik
                fputc(tekla, portua);
                break;
        }
        //Ekintzak onartzen direla adierazteko
        event->accept();
        //rfcomm portua itxi egingo da
        fclose(portua);

    }
//Play botoia sakatzen bada sortzen den ekintza
void Biraketanormal::on_hasiButton_clicked()
{
        //RFCOMM0 portua ireki
        FILE * portua = fopen ("/dev/rfcomm0", "w");
        //Mezuen kutxaren erazagupena
        QMessageBox infoBox,adosEzMezuaBox;

        //Abiadura aukeratu bada
        if(adosBai == true)
        {

        tekla='h';
        //'Play' botoia sakatu dela adierazten da aldagaiean
        hasiBai = true;
        //'Stop', 'Ados' eta Abiadura balioa aldatu dela egiaztatzeko aldagaia 'false' rekin hasieratzen da hurrengo aldirako
        stopBai = false;
        adosBai = false;
        abiadaldatuBai = false;
        //Mezua agertuko da prest dagoela esanaz
        infoBox.information(this,"PREST!","Dena prest dago,aurrera!");
        //'h'(hasi) tekla bidaltzen zaio robotaren programari RFCOMM0 portutik
        fputc(tekla,portua);
        //Aukeratu berri den abiadura bidatzel zaio robotaren programari RFCOMM0 portutik
        fputc(abiaduraBidali,portua);
        //Abiadura aukeratzailea desagertzen da 'Play' sakatzean
        ui->widget->hide();
        }
        //Abiadura aukeratu ez bada, abisu mezua agertuko zaizu
        else
        {
            adosEzMezuaBox.warning(this,"","Abiadura aukeratzea ahaztu zaizu");
        }
        //RFCOMM0 portua ixten da
        fclose(portua);
}

//Abiadura aukeratzailean, balioren bat aldatzean
void Biraketanormal::on_abiaduraAldatzailea_valueChanged(int arg1)
{
    //Abiaduraren balio berria esleitzen zaio aldagaiari
    abiadura=arg1;
    //Abiadura balio aldatu dela adierazteko
    abiadaldatuBai = true;
}
//Abiadura aukeratzean Ados botoia sakatzean sortzen den ekintza
void Biraketanormal::on_adosButton_clicked()
{
    QMessageBox adosMezua;
    adosMezua.information(this,"Abiadura aldaketa","Ongi!Abiadura eguneratu da");
    //Ados botoia sakatu dela adierazteko
    adosBai = true;
    //Abiadura balio aldatu bada
    if(abiadaldatuBai == true)
    {
        //Robotaren programari bidali behar zaion abiaduraren eguneratzea
        abiaduraBidali = (char)abiadura;
    }
    //Ez bada balioz aldatu, pantailan dagoen abiadura (50), bidaliko zaio robotari
    else
    {
        abiaduraBidali = '50';
    }

}

//Pause botoia sakatzen denean sortzen den ekintza
void Biraketanormal::on_pausaButton_clicked()
{
    //RFCOMM0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    tekla='p';
    //'p'(pause) tekla bidaltzen zaio robotaren programari RFCOMM0 portutik
    fputc(tekla,portua);
    //RFCOMM0 portua ixten da
    fclose(portua);
}

//Stop botoia sakatzen denean sortzen den ekintza
void Biraketanormal::on_stopButton_clicked()
{
    //RFCOMM0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    tekla='s';
    fputc(tekla,portua);
    //RFCOMM0 portua ixten da
    fclose(portua);
    //'Stop' botoia sakatu dela baieztatzeko
    stopBai = true;
}

//Menu nagusira bueltatzeko 'Atzera' botoia sakatzen denean sortzen den ekintza
void Biraketanormal::on_atzeraButton_clicked()
{
    //RFCOMM0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //robotaren programari atzera botoia sakatu dela komunikatzeko erabiliko den aldagaia
    tekla='a';
    //'a' tekla bidaliko zaio robotaren programari 'Atzera' botoia sakatu dela jakinarazteko
    fputc(tekla,portua);
    //RFCOMM0 portua ixten da
    fclose(portua);

}

//Aukera berrabiarazteko dagoen botoia sakatzean sortzen den ekintza
void Biraketanormal::on_berrabiaraziButton_clicked()
{
    //RFCOMM0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //robotaren programari 'Biraketa normal' modua aukeratzeko
    tekla='3';
    //'3' zenbakia bidaliko zaio robotaren programari 'mugitu_eskubi_ezker_normal' funtzioa martxan jarri dadin
    fputc(tekla,portua);
    //Abiadura aukeratzailea berriro erakusten da
    ui->widget->show();
    //RFCOMM0 portua ixten da
    fclose(portua);

}

//Menu nagusia erakusteko prozedura
void Biraketanormal::showNagusia()
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

//void Biraketanormal::showAzalpena()
//{
//    AzalpenaBiraketaNormal *azalpenabiraketanormal = new AzalpenaBiraketaNormal();
//    azalpenabiraketanormal->show();

//}

//Menu hedagarriko Maneiuari click eginez gero
void Biraketanormal::on_actionManeiua_triggered()
{
    QMessageBox maneiuaBox;
    //Maneiuaren azalpen mezua agertu
    maneiuaBox.setText("5 botoi dituzu menu honetan: Play,Pause,Stop,Berrabiarazi eta Atzera.\n\n Jolasten hasteko 'Play' botoiari eman behar diozu. 'Atzera' botoiari emateko aukera duzu eta menu nagusira joango da. 'Play' botoiari eman ondoren robota prest egongo da martxan jartzeko, aldiz momenturen batean robota geratu nahi baduzu aldi baterako, 'Pause'' botoiari emango diozu,eta berriro robota martxan jartzeko kurtsoreak erabiliko dituzu.\n\n Azkenik robota guztiz geratu nahi baduzu 'Stop' botoiari emango diozu, behin botoi hau sakaturik ezingo duzu robota mugitu 'Berrabiarazi' botoia sakatu ezean. 'Berrabiarazi' botoia sakatzean, dena hasieratuko da eta aukera izango duzu 'Play' botoiari sakatuta robota berriro martxan jartzeko.");
    maneiuaBox.exec();
    //maneiuaBox.information(this,"Maneiua","5 botoi ditugu menu honetan: Play,Pause,Stop,Berrabiarazi eta Atzera.\n\n Jolasten hasteko 'Play' botoiari eman behar diogu. 'Atzera' botoiari emateko aukera duzu eta menu nagusira joango da. 'Play' botoiari eman ondoren robota prest egongo da martxan jartzeko, aldiz momenturen batean robota geratu nahi baduzu aldi baterako, 'Pause'' botoiari emango zaio,eta berriro robota martxan jartzeko kurtsoreak erabiliko dira.\n\n Azkenik robota guztiz geratu nahi baduzu 'Stop' botoiari emango zaio, behin botoi hau sakaturik ezingo dugu robota mugitu 'Berrabiarazi' botoia sakatu ezean. 'Berrabiarazi' botoia sakatzean, dena hasieratuko da eta aukera izango duzu 'Play' botoiari sakatuta robota berriro martxan jartzeko.");
}

//Menu hedagarriko Kontrola-ri click eginez gero
void Biraketanormal::on_actionKontrolak_triggered()
{
    QMessageBox kontrolakBox;
    //Kontrolen azalpen mezua agertu
    kontrolakBox.setText("Robotaren  Wiimote-ko norabide botoiekin(aurrera/atzera(ezker/eskuin) kontrolatuko duzu. Lehendik abiadura finkatu duzunez,ez zara robota frenatzeaz kezkatu beharko.\n\n Aurrera edo atzera sakatuz gero, robota aukeraturiko abiaduran arituko da, aldiz ezker edo eskuin botoiak sakatuz gero 90º-ko bira egingo du sakaturiko norabidean");
    kontrolakBox.exec();
}


void Biraketanormal::on_actionAbiadura_aukeraketa_triggered()
{
    QMessageBox abiaduraAukeraketaBox;
    //Abiadura aukeraketaren azalpen mezua agertu
    abiaduraAukeraketaBox.setText("Modalitate honetan, robotak duen abiadura aukera dezakezu. Abiadura mugak 10-100 artean kokatzen dira.\n\n Nahi duzun abiadura aukeratzean, 'Ados' botoia sakatu beharko duzu, eta ondoren martxan jarri dadin 'Play' botoia sakatu.");
    abiaduraAukeraketaBox.exec();
}
