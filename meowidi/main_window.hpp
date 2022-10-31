#pragma once

#include <fluidsynth.h>
#include <QMainWindow>
#include <QWidget>

#include "forms/main_window.hpp"

class MainWindow: public QMainWindow {
	Q_OBJECT
	void setupSignals();
	void setupMidiPlayer();
public:
	explicit MainWindow(QWidget *parent = nullptr);
	virtual ~MainWindow();
private:
	Ui::MainWindow ui;

	fluid_settings_t* settings;
	fluid_synth_t* synth;
	fluid_player_t* player;
	fluid_audio_driver_t* driver;
};
