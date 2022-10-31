#pragma once

#include <fluidsynth.h>

class MidiPlayer {
public:
	MidiPlayer(const char* assetsPath);

	void addFile(const char* filename);

	void play();
	void pause();
	void stop();
	void reset();

	~MidiPlayer();
private:
	fluid_settings_t* settings;
	fluid_synth_t* synth;
	fluid_player_t* player;
	fluid_audio_driver_t* driver;
};