/********************************************************************************
** Form generated from reading UI file 'mandomugitu.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANDOMUGITU_H
#define UI_MANDOMUGITU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mandomugitu
{
public:
    QAction *actionManeiua;
    QAction *actionKontrolak;
    QWidget *centralwidget;
    QPushButton *pausaButton;
    QPushButton *stopButton;
    QPushButton *hasiButton;
    QPushButton *berrabiaraziButton;
    QPushButton *atzeraButton;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuLaguntza;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Mandomugitu)
    {
        if (Mandomugitu->objectName().isEmpty())
            Mandomugitu->setObjectName(QStringLiteral("Mandomugitu"));
        Mandomugitu->resize(400, 300);
        actionManeiua = new QAction(Mandomugitu);
        actionManeiua->setObjectName(QStringLiteral("actionManeiua"));
        actionKontrolak = new QAction(Mandomugitu);
        actionKontrolak->setObjectName(QStringLiteral("actionKontrolak"));
        centralwidget = new QWidget(Mandomugitu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pausaButton = new QPushButton(centralwidget);
        pausaButton->setObjectName(QStringLiteral("pausaButton"));
        pausaButton->setGeometry(QRect(170, 180, 50, 50));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Ikonoak/pause.gif"), QSize(), QIcon::Normal, QIcon::Off);
        pausaButton->setIcon(icon);
        pausaButton->setIconSize(QSize(200, 200));
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(310, 180, 51, 51));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Ikonoak/stop.gif"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon1);
        stopButton->setIconSize(QSize(200, 200));
        hasiButton = new QPushButton(centralwidget);
        hasiButton->setObjectName(QStringLiteral("hasiButton"));
        hasiButton->setGeometry(QRect(30, 180, 50, 50));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Ikonoak/play.gif"), QSize(), QIcon::Normal, QIcon::Off);
        hasiButton->setIcon(icon2);
        hasiButton->setIconSize(QSize(200, 200));
        berrabiaraziButton = new QPushButton(centralwidget);
        berrabiaraziButton->setObjectName(QStringLiteral("berrabiaraziButton"));
        berrabiaraziButton->setGeometry(QRect(310, 110, 51, 51));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Ikonoak/restart.png"), QSize(), QIcon::Normal, QIcon::Off);
        berrabiaraziButton->setIcon(icon3);
        berrabiaraziButton->setIconSize(QSize(40, 40));
        atzeraButton = new QPushButton(centralwidget);
        atzeraButton->setObjectName(QStringLiteral("atzeraButton"));
        atzeraButton->setGeometry(QRect(30, 110, 50, 50));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Ikonoak/atzera.png"), QSize(), QIcon::Normal, QIcon::Off);
        atzeraButton->setIcon(icon4);
        atzeraButton->setIconSize(QSize(35, 35));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 40, 191, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);
        Mandomugitu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Mandomugitu);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 25));
        menuLaguntza = new QMenu(menubar);
        menuLaguntza->setObjectName(QStringLiteral("menuLaguntza"));
        Mandomugitu->setMenuBar(menubar);
        statusbar = new QStatusBar(Mandomugitu);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Mandomugitu->setStatusBar(statusbar);

        menubar->addAction(menuLaguntza->menuAction());
        menuLaguntza->addAction(actionManeiua);
        menuLaguntza->addAction(actionKontrolak);

        retranslateUi(Mandomugitu);
        QObject::connect(atzeraButton, SIGNAL(clicked()), Mandomugitu, SLOT(showNagusia()));

        QMetaObject::connectSlotsByName(Mandomugitu);
    } // setupUi

    void retranslateUi(QMainWindow *Mandomugitu)
    {
        Mandomugitu->setWindowTitle(QApplication::translate("Mandomugitu", "Laguntza", 0));
        actionManeiua->setText(QApplication::translate("Mandomugitu", "Maneiua", 0));
        actionKontrolak->setText(QApplication::translate("Mandomugitu", "Kontrolak", 0));
        pausaButton->setText(QString());
        stopButton->setText(QString());
        hasiButton->setText(QString());
        berrabiaraziButton->setText(QString());
        atzeraButton->setText(QString());
        label->setText(QApplication::translate("Mandomugitu", "Wiimote-a Mugituz", 0));
        menuLaguntza->setTitle(QApplication::translate("Mandomugitu", "Laguntza", 0));
    } // retranslateUi

};

namespace Ui {
    class Mandomugitu: public Ui_Mandomugitu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANDOMUGITU_H
