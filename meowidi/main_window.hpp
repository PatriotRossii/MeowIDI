#pragma once

#include <fluidsynth.h>
#include <QMainWindow>
#include <QWidget>

#include "forms/main_window.hpp"

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

class MainWindow: public QMainWindow {
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = nullptr);
	virtual ~MainWindow();
private slots:
	void on_actionOpen_triggered();

	void on_actionPlay_triggered();
	void on_actionPause_triggered();
	void on_actionStop_triggered();

	void on_actionExit_triggered();

	void on_actionVisit_Website_triggered();
	void on_actionAbout_triggered();
private:
	Ui::MainWindow ui;

	fluid_settings_t* settings;
	fluid_synth_t* synth;
	fluid_player_t* player;
	fluid_audio_driver_t* driver;
};
