#ifndef SOUND_HPP_
# define SOUND_HPP_

#include <SFML/Audio.hpp>

class Sound
{
public:
    Sound();
    ~Sound();
    void playSound();
private:
    sf::Music _music;

};
#endif //SOUND_HPP_