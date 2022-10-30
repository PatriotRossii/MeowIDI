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

	settings = new_fluid_settings();
	synth = new_fluid_synth(settings);
	player = new_fluid_player(synth);

	fluid_synth_sfload(synth, "../assets/samples.sf2", 1);
	driver = new_fluid_audio_driver(settings, synth);

	std::thread([this]() {
		fluid_player_join(player);
	}).detach();
}

void MainWindow::on_actionOpen_triggered() {
	std::string fileName = QFileDialog::getOpenFileName(
		this, "Open midi file", "/home", "Midi files (*.mid *.midi)"
	).toStdString();
	if (!fileName.empty()) {
		fluid_player_add(player, fileName.c_str());
	}
}

void MainWindow::on_actionPlay_triggered() {
	fluid_player_play(player);
}

void MainWindow::on_actionStop_triggered() {
	fluid_player_stop(player);
}

void MainWindow::on_actionExit_triggered() {
	qApp->closeAllWindows();
}

void MainWindow::on_actionVisit_Website_triggered() {
	QDesktopServices::openUrl(QUrl("https:\/\/github.com/PatriotRossii/MeowIDI"));
}

void MainWindow::on_actionAbout_triggered() {
	QMessageBox::information(this, "About", "MeowIDI is an open-source midi player!");
}

MainWindow::~MainWindow() {
	delete_fluid_audio_driver(driver);
	delete_fluid_player(player);
	delete_fluid_synth(synth);
	delete_fluid_settings(settings);
}
