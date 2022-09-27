#include "../../include/core/Audio.h"

Sound SoundLoad(const char* file){
    Wave sfx = LoadWave(file);
    Sound sound = LoadSoundFromWave(sfx);
    UnloadWave(sfx);

    return sound;
}

void PlayRefSound(Sound Song){
    if(IsAudioDeviceReady()){
        PlaySound(Song);
    }
}