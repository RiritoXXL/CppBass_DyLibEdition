#include "includes.h"

int main() {
	LPCSTR stringexample = (LPCSTR)"ExampleBass.mp3";
	SetConsoleTitleA("CppBass-DylibEdition by RiritoXXL");
	BASS_INIT();
	BASS_Start();
	uint32_t handle_bass = BASS_StreamCreateFile(stringexample, BASS_LOOP);
	BASS_ChannelPlay(handle_bass);
	while (true) {
		Sleep(4000);
	}
	return 0;
}
