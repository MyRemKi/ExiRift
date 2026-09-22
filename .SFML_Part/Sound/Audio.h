#ifndef AUDIO_H
#define AUDIO_H
#include "SFML/Audio.hpp"
#pragma once

class Audio :
{
public:
    Audio(string path="");
    void play();
    void stop();
    void setVolume(float volume);
    void setLoop(bool loop);
    void setPosition(float x, float y, float z);
    void setPositionSoundMob(float x, float y, float z);
    ~Audio();

private:
    sf::SoundBuffer buffer;
    sf::Sound sound;
};

#endif