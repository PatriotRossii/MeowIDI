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
#include <thread>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent) {
	ui.setupUi(this);

	setupMidiPlayer();
	setupSignals();
}

void MainWindow::setupSignals() {
	QObject::connect(ui.actionOpen, &QAction::triggered, this, [this]() {
		std::string fileName = QFileDialog::getOpenFileName(
			this, "Open midi file", "/home", "Midi files (*.mid *.midi)"
		).toStdString();

		fluid_player_stop(player);
		fluid_player_join(player);
		player = new_fluid_player(synth);

		if (!fileName.empty()) {
			fluid_player_add(player, fileName.c_str());
		}
	});

	QObject::connect(ui.actionPlay, &QAction::triggered, this, [this]() {
		fluid_player_play(player);
	});
	QObject::connect(ui.actionPause, &QAction::triggered, this, [this]() {
		fluid_player_stop(player);
	});
	QObject::connect(ui.actionStop, &QAction::triggered, this, [this]() {
		fluid_player_stop(player);
		fluid_player_seek(player, 0);
	});

	QObject::connect(ui.actionExit, &QAction::triggered, this, [this]() {
		qApp->closeAllWindows();
	});

	QObject::connect(ui.actionWebsite, &QAction::triggered, this, [this]() {
		QDesktopServices::openUrl(QUrl("https://github.com/PatriotRossii/MeowIDI"));
	});
	QObject::connect(ui.actionAbout, &QAction::triggered, this, [this]() {
		QMessageBox::information(this, "About", "MeowIDI is an open-source midi player!");
	});
}

void MainWindow::setupMidiPlayer() {
	settings = new_fluid_settings();
	synth = new_fluid_synth(settings);
	player = new_fluid_player(synth);

	fluid_synth_sfload(synth, "../assets/samples.sf2", 1);
	driver = new_fluid_audio_driver(settings, synth);

	std::thread([this]() {
		while(true) {
			fluid_player_join(player);
		}
	}).detach();
}

MainWindow::~MainWindow() {
	delete_fluid_audio_driver(driver);
	delete_fluid_player(player);
	delete_fluid_synth(synth);
	delete_fluid_settings(settings);
}
