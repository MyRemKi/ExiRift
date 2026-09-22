#include "Audio.h"

Audio::Audio(string path)
{
    if (!buffer.loadFromFile(path))
    {
        // Handle error
    }
    else{
        
    }
}

void Audio::play()
{
    sound.setBuffer(buffer);
    sound.play();
}

void Audio::stop()
{
    sound.stop();
}

void Audio::setVolume(float volume, float x=0, float y=0, float z=0)
{
    if(x != 0 || y != 0 || z != 0   ){
        sound.setPosition(x, y, z);
    }
    sound.setVolume(volume);
}

void Audio::setLoop(bool loop)
{
    sound.setLoop(loop);
}

void Audio::setPosition(float x, float y, float z)
{
    sound.setPosition(x, y, z);
}

Audio::~Audio()
{

}