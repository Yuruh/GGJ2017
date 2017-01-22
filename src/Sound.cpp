//
// Created by thomas on 22/01/17.
//

#include <Sound.hpp>

Sound::Sound() {
   _music.openFromFile("resources/assets/sound/terra.ogg");

}

Sound::~Sound() {

}

void Sound::playSound()
{
    _music.play();
}
