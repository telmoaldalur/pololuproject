#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>

//Aldagai globalak
char zenbakia;
char aukera;
int hasiera=0;
//Stop eta Hasi botoiak sakatu diren egiaztatzeko aldagaia
bool stopBai,hasiBai,adosBai,abiadaldatuBai;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QMessageBox konfigurazioaMezuak;

    if(hasiera!=1)
    {
        hasiera = 1;
        system("rfcomm release 0");
        //Pololu-PC-ren arteko bluetooth konexioa ahalbidetzen da
        system("rfcomm connect 0 00:06:66:4E:08:72 &");
        //Wiimote-ak arratoia emulatuko du
        system("wminput -w &");
        konfigurazioaMezuak.information(this,"Konfigurazioa","Itxaron roboteko Bluetooth moduloan argi horia piztu arte.\n\n Wiimote-a konfiguratzeko:Wiimote-ko 1 eta 2 botoiak sakatzen egon 8 segunduz.Ongi burutu dela egiaztatzeko mugitu Wiimote-a arratoia balitz bezala");
    }

    ui->setupUi(this);
    
    ui->azeleratuzButton->setToolTip("Pololu robota Wii-ko mandoaren kurtsoreekin kontrolatzeko aukera izango duzu.\n Gora/behera/ezker/eskuin kurtsoreak sakatzen egon ezkero robota azeleratzen joango da.");
    ui->biraketaNormalButton->setToolTip("Pololu robota Wii-ko mandoaren kurtsoreekin kontrolatzeko aukera izango duzu\n. Ezker/eskuin kurtsoreak sakatuz gero, robota norabide horretan giraka egongo da etengabe, aurrera edo atzera sakatu bitartean. ");
    ui->biraketaZoroaButton->setToolTip("Pololu robota Wii-ko mandoaren kurtsoreekin kontrolatzeko aukera izango duzu.\n Ezker/eskuin kurtsoreak sakatuz gero, 90º-ko bira egingo du aukeraturiko norabidean. ");
    ui->mandoaMugituzButton->setToolTip("Pololu robota Wii-ko mandoarekin kontrolatzeko aukera izango duzu");





}

MainWindow::~MainWindow()
{
    delete ui;

}

//Aukera ezberdinetara joateko botoien ekintzak

//Wiimote-a mugituz botoia sakatuz gero sortzen den ekintza
void MainWindow::on_mandoaMugituzButton_clicked()
{
    //robotaren programari bidaliko zaion aukeraketa aldagari '1' zenbakia esleitzen zaio
    zenbakia = '1';
    //rfcomm0 portua ireki

    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //Sakaturiko botoiaren 'zenbakia' aldagaia bidaltzen zaio robotaren programari RFCOMM0 portutik
    fputc(zenbakia,portua);
    //RFCOMM0 portua ixten da
    fclose(portua);
    //Menu nagusia desagertzen da
    this->hide();
    //Sakaturiko botoiaren menua azalduko da
    mandomugitu.show();

}

void MainWindow::on_biraketaZoroaButton_clicked()
{
    //robotaren programari bidaliko zaion aukeraketa aldagari '2' zenbakia esleitzen zaio
    zenbakia = '2';
    //RFCOMM0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //Sakaturiko botoiaren 'zenbakia' aldagaia bidaltzen zaio robotaren programari RFCOMM0 portutik
    fputc(zenbakia,portua);
    //RFCOMM0 portua ixten da
    fclose(portua);
    //Menu nagusia desagertzen da
    this->hide();
    //Sakaturiko botoiaren menua azalduko da
    biraketazoro.show();

}

void MainWindow::on_biraketaNormalButton_clicked()
{
    //robotaren programari bidaliko zaion aukeraketa aldagari '3' zenbakia esleitzen zaio
    zenbakia = '3';
    //rfcomm0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //Sakaturiko botoiaren 'zenbakia' aldagaia bidaltzen zaio robotaren programari RFCOMM0 portutik
    fputc(zenbakia,portua);
    //RFCOMM0 portua ixten da
    fclose(portua);
    //Menu nagusia desagertzen da
    this->hide();
    //Sakaturiko botoiaren menua azalduko da
    biraketanormal.show();
}


void MainWindow::on_azeleratuzButton_clicked()
{
    //robotaren programari bidaliko zaion aukeraketa aldagari '4' zenbakia esleitzen zaio
    zenbakia = '4';
    //rfcomm0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //Sakaturiko botoiaren 'zenbakia' aldagaia bidaltzen zaio robotaren programari RFCOMM0 portutik
    fputc(zenbakia,portua);
    //RFCOMM0 portua ixten da
    fclose(portua);
    //Menu nagusia desagertzen da
    this->hide();
    //Sakaturiko botoiaren menua azalduko da
    azeleratuz.show();

}




void MainWindow::on_bukatuButton_clicked()
{
    char tekla;
    //rfcomm0 portua ireki
    FILE * portua = fopen ("/dev/rfcomm0", "w");
    //Programa itxi nahi dudaneko msgboxa
    QMessageBox itxiBox,itzaliPololu;
    itxiBox.setText("Programa itxi nahi duzu?");
    //Bai aukera sakatzen dudanerako objektua
    QAbstractButton *baiButton = itxiBox.addButton(trUtf8("Bai"), QMessageBox::YesRole);
    itxiBox.addButton(trUtf8("Ez"), QMessageBox::NoRole);
    //Msgbox-ari galdera itxura ematen dio
    itxiBox.setIcon(QMessageBox::Question);
    itxiBox.exec();
    //Bai sakatuz gero programa itxiko da guztiz
    if(itxiBox.clickedButton() == baiButton)
    {
        itzaliPololu.information(this,"Itzali robota","Mesedez pololu robota itzal ezazu 'Power' botoiari emanaz");
        tekla='i';
        //Robotari komunikatuko dio robota itzali behar dela
        fputc(tekla,portua);
        fclose(portua);
        //Menua desagertuko da
        this->hide();
        //Interfazearen programa guztiz itxiko da
        close();
    }

}
