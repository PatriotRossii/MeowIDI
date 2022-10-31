#include "midi_player.hpp"
#include "main_window.hpp"

#include <QApplication>
#include <QVBoxLayout>
#include <QUrl>
#include <QFile>
#include <QAction>
#include <QUiLoader>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices> 

#include <string>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), player("../assets/samples.sf2") {
	ui.setupUi(this);
	setupSignals();
}

void MainWindow::setupSignals() {
	QObject::connect(ui.actionOpen, &QAction::triggered, this, [this]() {
		std::string fileName = QFileDialog::getOpenFileName(
			this, tr("Open midi file"), "/home", tr("Midi files (*.mid *.midi)")
		).toStdString();

		if (!fileName.empty()) {
			player.reset();
			player.addFile(fileName.c_str());
		}
	});

	QObject::connect(ui.actionPlay, &QAction::triggered, this, [this]() { player.play(); });
	QObject::connect(ui.actionPause, &QAction::triggered, this, [this]() { player.pause(); });
	QObject::connect(ui.actionStop, &QAction::triggered, this, [this]() { player.stop(); });

	QObject::connect(ui.actionExit, &QAction::triggered, this, [this]() {
		qApp->closeAllWindows();
	});

	QObject::connect(ui.actionWebsite, &QAction::triggered, this, [this]() {
		QDesktopServices::openUrl(QUrl("https://github.com/PatriotRossii/MeowIDI"));
	});
	QObject::connect(ui.actionAbout, &QAction::triggered, this, [this]() {
		QMessageBox::information(this, tr("About"), tr("MeowIDI is an open-source midi player!"));
	});
}
