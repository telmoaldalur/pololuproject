/********************************************************************************
** Form generated from reading UI file 'biraketanormal.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIRAKETANORMAL_H
#define UI_BIRAKETANORMAL_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Biraketanormal
{
public:
    QAction *actionManeiua;
    QAction *actionKontrolak;
    QAction *actionAbiadura_aukeraketa;
    QWidget *centralwidget;
    QWidget *widget;
    QSpinBox *abiaduraAldatzailea;
    QPushButton *adosButton;
    QPushButton *pausaButton;
    QPushButton *stopButton;
    QPushButton *hasiButton;
    QPushButton *berrabiaraziButton;
    QPushButton *atzeraButton;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menuLaguntza;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Biraketanormal)
    {
        if (Biraketanormal->objectName().isEmpty())
            Biraketanormal->setObjectName(QStringLiteral("Biraketanormal"));
        Biraketanormal->resize(400, 300);
        Biraketanormal->setFocusPolicy(Qt::ClickFocus);
        Biraketanormal->setLayoutDirection(Qt::LeftToRight);
        actionManeiua = new QAction(Biraketanormal);
        actionManeiua->setObjectName(QStringLiteral("actionManeiua"));
        actionKontrolak = new QAction(Biraketanormal);
        actionKontrolak->setObjectName(QStringLiteral("actionKontrolak"));
        actionAbiadura_aukeraketa = new QAction(Biraketanormal);
        actionAbiadura_aukeraketa->setObjectName(QStringLiteral("actionAbiadura_aukeraketa"));
        centralwidget = new QWidget(Biraketanormal);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(120, 60, 171, 111));
        widget->setFocusPolicy(Qt::StrongFocus);
        widget->setAcceptDrops(false);
        widget->setAutoFillBackground(true);
        abiaduraAldatzailea = new QSpinBox(widget);
        abiaduraAldatzailea->setObjectName(QStringLiteral("abiaduraAldatzailea"));
        abiaduraAldatzailea->setGeometry(QRect(50, 20, 48, 27));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 255, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(127, 255, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(63, 255, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(0, 127, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(0, 170, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        abiaduraAldatzailea->setPalette(palette);
        abiaduraAldatzailea->setFocusPolicy(Qt::StrongFocus);
        abiaduraAldatzailea->setWrapping(false);
        abiaduraAldatzailea->setMinimum(10);
        abiaduraAldatzailea->setMaximum(100);
        abiaduraAldatzailea->setSingleStep(10);
        abiaduraAldatzailea->setValue(50);
        abiaduraAldatzailea->setDisplayIntegerBase(10);
        adosButton = new QPushButton(widget);
        adosButton->setObjectName(QStringLiteral("adosButton"));
        adosButton->setGeometry(QRect(50, 70, 61, 27));
        pausaButton = new QPushButton(centralwidget);
        pausaButton->setObjectName(QStringLiteral("pausaButton"));
        pausaButton->setGeometry(QRect(180, 180, 50, 50));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Ikonoak/pause.gif"), QSize(), QIcon::Normal, QIcon::Off);
        pausaButton->setIcon(icon);
        pausaButton->setIconSize(QSize(200, 200));
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(320, 180, 51, 51));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Ikonoak/stop.gif"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon1);
        stopButton->setIconSize(QSize(200, 200));
        hasiButton = new QPushButton(centralwidget);
        hasiButton->setObjectName(QStringLiteral("hasiButton"));
        hasiButton->setGeometry(QRect(40, 180, 50, 50));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Ikonoak/play.gif"), QSize(), QIcon::Normal, QIcon::Off);
        hasiButton->setIcon(icon2);
        hasiButton->setIconSize(QSize(200, 200));
        berrabiaraziButton = new QPushButton(centralwidget);
        berrabiaraziButton->setObjectName(QStringLiteral("berrabiaraziButton"));
        berrabiaraziButton->setGeometry(QRect(320, 120, 51, 51));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Ikonoak/restart.png"), QSize(), QIcon::Normal, QIcon::Off);
        berrabiaraziButton->setIcon(icon3);
        berrabiaraziButton->setIconSize(QSize(40, 40));
        atzeraButton = new QPushButton(centralwidget);
        atzeraButton->setObjectName(QStringLiteral("atzeraButton"));
        atzeraButton->setGeometry(QRect(40, 120, 50, 50));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Ikonoak/atzera.png"), QSize(), QIcon::Normal, QIcon::Off);
        atzeraButton->setIcon(icon4);
        atzeraButton->setIconSize(QSize(35, 35));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 10, 151, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_2->setFont(font);
        Biraketanormal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Biraketanormal);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 25));
        menuLaguntza = new QMenu(menubar);
        menuLaguntza->setObjectName(QStringLiteral("menuLaguntza"));
        Biraketanormal->setMenuBar(menubar);
        statusbar = new QStatusBar(Biraketanormal);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Biraketanormal->setStatusBar(statusbar);

        menubar->addAction(menuLaguntza->menuAction());
        menuLaguntza->addAction(actionManeiua);
        menuLaguntza->addAction(actionKontrolak);
        menuLaguntza->addAction(actionAbiadura_aukeraketa);

        retranslateUi(Biraketanormal);
        QObject::connect(atzeraButton, SIGNAL(clicked()), Biraketanormal, SLOT(showNagusia()));

        QMetaObject::connectSlotsByName(Biraketanormal);
    } // setupUi

    void retranslateUi(QMainWindow *Biraketanormal)
    {
        Biraketanormal->setWindowTitle(QApplication::translate("Biraketanormal", "Laguntza", 0));
        actionManeiua->setText(QApplication::translate("Biraketanormal", "Maneiua", 0));
        actionKontrolak->setText(QApplication::translate("Biraketanormal", "Kontrolak", 0));
        actionAbiadura_aukeraketa->setText(QApplication::translate("Biraketanormal", "Abiadura aukeraketa", 0));
        adosButton->setText(QApplication::translate("Biraketanormal", "Ados", 0));
        pausaButton->setText(QString());
        stopButton->setText(QString());
        hasiButton->setText(QString());
        berrabiaraziButton->setText(QString());
        atzeraButton->setText(QString());
        label_2->setText(QApplication::translate("Biraketanormal", "Biraketa Normal", 0));
        menuLaguntza->setTitle(QApplication::translate("Biraketanormal", "Laguntza", 0));
    } // retranslateUi

};

namespace Ui {
    class Biraketanormal: public Ui_Biraketanormal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIRAKETANORMAL_H
