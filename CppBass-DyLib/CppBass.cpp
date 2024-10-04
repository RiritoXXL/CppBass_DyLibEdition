#include "includes.h"

int main() {
	LPCWSTR stringexample = (LPCWSTR)"ExampleBass.mp3";
	BASS_INIT();
	BASS_Start();
	uint32_t handle_bass = BASS_StreamCreateFile(stringexample);
	BASS_ChannelPlay(handle_bass);
	while (true) {
		Sleep(4000);
	}
	return 0;
}