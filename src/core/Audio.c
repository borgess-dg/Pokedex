#include "../../include/core/Audio.h"

void PlayCoinSound(void){
    Wave wave_sfx = LoadWave("./assets/Audio/pickupCoin.wav");
    Sound sfx = LoadSoundFromWave(wave_sfx);

    if(IsAudioDeviceReady()){
        PlaySound(sfx);
    }
}

void PlayPowerUpSound(void){
    Wave wave_sfx = LoadWave("./assets/Audio/powerUp.wav");
    Sound sfx = LoadSoundFromWave(wave_sfx);

    if(IsAudioDeviceReady()){
        PlaySound(sfx);
    }
}