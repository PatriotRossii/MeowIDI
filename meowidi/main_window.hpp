#pragma once

#include <QMainWindow>
#include <QWidget>

#include "forms/main_window.hpp"
#include "midi_player.hpp"

class MainWindow: public QMainWindow {
	Q_OBJECT
	void setupSignals();
public:
	explicit MainWindow(QWidget *parent = nullptr);
	virtual ~MainWindow() { }
private:
	Ui::MainWindow ui;
	MidiPlayer player;
};
