#pragma once
#include <Windows.h>
#include <iostream>
#include <dylib.hpp>
using namespace std;
#define BASS_LOOP 4
dylib GetDLL() {
	dylib lib(".\\lib", "bass");
	return lib;
}

void BASS_INIT() {
	auto BASS_Init = GetDLL().get_function<bool(int, int, int, int, int)>("BASS_Init");
	if (!BASS_Init(-1, 48000, 0, 0, 0)) {
		cout << "Failed to Execute BASS" << endl;
	}
	else {
		cout << "Successfully Initializated BASS Driver(Un4seen Module)" << endl;
	}
}

void BASS_Start() {
	auto BASS_Start = GetDLL().get_function<bool()>("BASS_Start");
	if (BASS_Start()) 
	{
		printf("Bass Is Started!!!");
	}
	else {
		printf("Failed!!!");
	}
}

uint32_t BASS_StreamCreateFile(LPCWSTR str) {
	auto BASS_StreamCreateFile = GetDLL().get_function<uint32_t(bool, LPCTSTR, int, int, int)>("BASS_StreamCreateFile");
	return BASS_StreamCreateFile(false, str, 0, 0, BASS_LOOP);
}

void BASS_ChannelPlay(uint32_t handle) 
{
	auto BASS_ChannelPlay = GetDLL().get_function<void(uint32_t, bool)>("BASS_ChannelPlay");
	BASS_ChannelPlay(handle, false);
}