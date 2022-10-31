#include "midi_player.hpp"

#include <thread>

MidiPlayer::MidiPlayer(const char* assetsPath) {
	settings = new_fluid_settings();
	synth = new_fluid_synth(settings);
	player = new_fluid_player(synth);

	fluid_synth_sfload(synth, assetsPath, 1);
	driver = new_fluid_audio_driver(settings, synth);

	std::thread([this]() {
		while(true) {
			fluid_player_join(player);
		}
	}).detach();
}

void MidiPlayer::addFile(const char* filename) {
	fluid_player_add(player, filename);
}

void MidiPlayer::play() {
	fluid_player_play(player);
}

void MidiPlayer::pause() {
	fluid_player_stop(player);
}

void MidiPlayer::stop() {
	fluid_player_stop(player);
	fluid_player_seek(player, 0);
}

void MidiPlayer::reset() {
	fluid_player_stop(player);
	fluid_player_join(player);

	// I know that we have a memory leak here, but it's okay, I assure you
	player = new_fluid_player(synth);
}

MidiPlayer::~MidiPlayer() {
	delete_fluid_audio_driver(driver);
	delete_fluid_player(player);
	delete_fluid_synth(synth);
	delete_fluid_settings(settings);
}
