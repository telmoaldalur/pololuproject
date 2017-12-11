/********************************************************************************
** Form generated from reading UI file 'azeleratuz.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AZELERATUZ_H
#define UI_AZELERATUZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Azeleratuz
{
public:
    QAction *actionManeiua;
    QAction *actionKontrolak;
    QWidget *centralwidget;
    QLCDNumber *lcdNumber;
    QPushButton *berrabiaraziButton;
    QLabel *label;
    QPushButton *atzeraButton;
    QPushButton *pausaButton;
    QPushButton *stopButton;
    QPushButton *hasiButton;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menuLaguntza;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Azeleratuz)
    {
        if (Azeleratuz->objectName().isEmpty())
            Azeleratuz->setObjectName(QStringLiteral("Azeleratuz"));
        Azeleratuz->resize(400, 300);
        Azeleratuz->setWindowTitle(QStringLiteral("Laguntza"));
        actionManeiua = new QAction(Azeleratuz);
        actionManeiua->setObjectName(QStringLiteral("actionManeiua"));
        actionKontrolak = new QAction(Azeleratuz);
        actionKontrolak->setObjectName(QStringLiteral("actionKontrolak"));
        centralwidget = new QWidget(Azeleratuz);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(160, 80, 81, 51));
        berrabiaraziButton = new QPushButton(centralwidget);
        berrabiaraziButton->setObjectName(QStringLiteral("berrabiaraziButton"));
        berrabiaraziButton->setGeometry(QRect(310, 106, 51, 51));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Ikonoak/restart.png"), QSize(), QIcon::Normal, QIcon::Off);
        berrabiaraziButton->setIcon(icon);
        berrabiaraziButton->setIconSize(QSize(40, 40));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 60, 91, 17));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        atzeraButton = new QPushButton(centralwidget);
        atzeraButton->setObjectName(QStringLiteral("atzeraButton"));
        atzeraButton->setGeometry(QRect(30, 110, 50, 50));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Ikonoak/atzera.png"), QSize(), QIcon::Normal, QIcon::Off);
        atzeraButton->setIcon(icon1);
        atzeraButton->setIconSize(QSize(35, 35));
        pausaButton = new QPushButton(centralwidget);
        pausaButton->setObjectName(QStringLiteral("pausaButton"));
        pausaButton->setGeometry(QRect(170, 170, 50, 50));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Ikonoak/pause.gif"), QSize(), QIcon::Normal, QIcon::Off);
        pausaButton->setIcon(icon2);
        pausaButton->setIconSize(QSize(200, 200));
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(310, 170, 51, 51));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Ikonoak/stop.gif"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon3);
        stopButton->setIconSize(QSize(200, 200));
        hasiButton = new QPushButton(centralwidget);
        hasiButton->setObjectName(QStringLiteral("hasiButton"));
        hasiButton->setGeometry(QRect(30, 170, 50, 50));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Ikonoak/play.gif"), QSize(), QIcon::Normal, QIcon::Off);
        hasiButton->setIcon(icon4);
        hasiButton->setIconSize(QSize(200, 200));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 0, 101, 31));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        Azeleratuz->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Azeleratuz);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 25));
        menuLaguntza = new QMenu(menubar);
        menuLaguntza->setObjectName(QStringLiteral("menuLaguntza"));
        Azeleratuz->setMenuBar(menubar);
        statusbar = new QStatusBar(Azeleratuz);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Azeleratuz->setStatusBar(statusbar);

        menubar->addAction(menuLaguntza->menuAction());
        menuLaguntza->addAction(actionManeiua);
        menuLaguntza->addAction(actionKontrolak);

        retranslateUi(Azeleratuz);
        QObject::connect(atzeraButton, SIGNAL(clicked()), Azeleratuz, SLOT(showNagusia()));

        QMetaObject::connectSlotsByName(Azeleratuz);
    } // setupUi

    void retranslateUi(QMainWindow *Azeleratuz)
    {
        actionManeiua->setText(QApplication::translate("Azeleratuz", "Maneiua", 0));
        actionKontrolak->setText(QApplication::translate("Azeleratuz", "Kontrolak", 0));
        berrabiaraziButton->setText(QString());
        label->setText(QApplication::translate("Azeleratuz", "Abiadura", 0));
        atzeraButton->setText(QString());
        pausaButton->setText(QString());
        stopButton->setText(QString());
        hasiButton->setText(QString());
        label_2->setText(QApplication::translate("Azeleratuz", "Azeleratuz", 0));
        menuLaguntza->setTitle(QApplication::translate("Azeleratuz", "Laguntza", 0));
        Q_UNUSED(Azeleratuz);
    } // retranslateUi

};

namespace Ui {
    class Azeleratuz: public Ui_Azeleratuz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AZELERATUZ_H
