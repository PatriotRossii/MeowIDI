#include <fluidsynth.h>
#include <iostream>

int main(int argc, char** argv) {
	fluid_settings_t* settings = new_fluid_settings();
	fluid_synth_t* synth = new_fluid_synth(settings);
	fluid_player_t* player = new_fluid_player(synth);

	for(int i = 1; i != argc; ++i) {
		if (fluid_is_soundfont(argv[i])) {
			fluid_synth_sfload(synth, argv[1], 1);
			std::cout << "Got soundfont" << '\n';
		}
		if (fluid_is_midifile(argv[i])) {
			fluid_player_add(player, argv[i]);
			std::cout << "Got midi file" << '\n';
		}
	}

	fluid_audio_driver_t* driver = new_fluid_audio_driver(settings, synth);
	fluid_player_play(player);
	fluid_player_join(player);

	delete_fluid_audio_driver(driver);
	delete_fluid_player(player);
	delete_fluid_synth(synth);
	delete_fluid_settings(settings);
}