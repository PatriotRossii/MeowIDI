/********************************************************************************
** Form generated from reading UI file 'main_windowavCHNC.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAIN_WINDOWAVCHNC_H
#define MAIN_WINDOWAVCHNC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

#include <QTranslator>
#include <QKeySequence>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionVisit_Website;
    QAction *actionAbout;
    QAction *actionOpen;
    QAction *actionPlay;
    QAction *actionStop;
    QAction *actionExit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFiles;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(538, 176);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);

        actionVisit_Website = new QAction(QObject::tr("&Visit Website"), MainWindow);
        actionVisit_Website->setObjectName(QString::fromUtf8("actionVisit_Website"));

        actionAbout = new QAction(QObject::tr("&About"), MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));

        actionOpen = new QAction(QObject::tr("&Open"), MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionOpen->setShortcuts(QKeySequence::Open);

        actionPlay = new QAction(QObject::tr("&Play"), MainWindow);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        actionPlay->setShortcut(QKeySequence(Qt::Key_MediaPlay));

        actionStop = new QAction(QObject::tr("&Stop"), MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionStop->setShortcut(QKeySequence(Qt::Key_MediaStop));

        actionExit = new QAction(QObject::tr("&Exit"), MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionExit->setShortcuts(QKeySequence::Quit);

        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 538, 22));
        menubar->setDefaultUp(false);
        menuFiles = new QMenu(menubar);
        menuFiles->setObjectName(QString::fromUtf8("menuFiles"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFiles->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFiles->addAction(actionOpen);
        menuFiles->addSeparator();
        menuFiles->addAction(actionPlay);
        menuFiles->addAction(actionStop);
        menuFiles->addSeparator();
        menuFiles->addAction(actionExit);
        menuHelp->addSeparator();
        menuHelp->addAction(actionVisit_Website);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MeowIDI", nullptr));
        menuFiles->setTitle(QCoreApplication::translate("MainWindow", "&Files", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAIN_WINDOWAVCHNC_H
