#pragma once

#include <QApplication>
#include <QKeySequence>
#include <QMainWindow>
#include <QTranslator>
#include <QStatusBar>
#include <QMenuBar>
#include <QVariant>
#include <QWidget>
#include <QAction>
#include <QMenu>

namespace Ui {

class MainWindow
{
public:
    QAction *actionOpen, *actionPlay, *actionPause, *actionStop, *actionExit;
    QAction *actionWebsite, *actionAbout;

    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFiles, *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow) {
        centralwidget = new QWidget(MainWindow);
        MainWindow->setCentralWidget(centralwidget);

        /* 1. QMenuBar */

        menubar = new QMenuBar(MainWindow);
        MainWindow->setMenuBar(menubar);

        /* 1.1. Files menu */

        menuFiles = new QMenu(QObject::tr("&Files"), menubar);
        menubar->addAction(menuFiles->menuAction());

        actionOpen = new QAction(QObject::tr("&Open"), MainWindow);
        actionOpen->setShortcuts(QKeySequence::Open);
        menuFiles->addAction(actionOpen);

        menuFiles->addSeparator();

        actionPlay = new QAction(QObject::tr("&Play"), MainWindow);
        actionPlay->setShortcut(QKeySequence(Qt::Key_MediaPlay));
        menuFiles->addAction(actionPlay);

        actionPause = new QAction(QObject::tr("P&ause"), MainWindow);
        actionPause->setShortcut(QKeySequence(Qt::Key_MediaPause));
        menuFiles->addAction(actionPause);

        actionStop = new QAction(QObject::tr("&Stop"), MainWindow);
        actionStop->setShortcut(QKeySequence(Qt::Key_MediaStop));
        menuFiles->addAction(actionStop);

        menuFiles->addSeparator();
        actionExit = new QAction(QObject::tr("&Exit"), MainWindow);
        actionExit->setShortcuts(QKeySequence::Quit);
        menuFiles->addAction(actionExit);

        /* 1.1. End of files menu */
        /* 1.2 Help menu */

        menuHelp = new QMenu(QObject::tr("&Help"), menubar);
        menubar->addAction(menuHelp->menuAction());

        actionWebsite = new QAction(QObject::tr("&Visit Website"), MainWindow);
        menuHelp->addAction(actionWebsite);

        actionAbout = new QAction(QObject::tr("&About"), MainWindow);
        menuHelp->addAction(actionAbout);

        /* 1.2 End of help menu */
        /* 1. End of QMenuBar */

        retranslateUi(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow) {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MeowIDI", nullptr));
    } // retranslateUi

};

} // namespace Ui
