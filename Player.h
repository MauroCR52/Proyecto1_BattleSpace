#ifndef PROYECTO1_BATTLESPACE_PLAYER_H
#define PROYECTO1_BATTLESPACE_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "iostream"
using namespace sf;
class Player {

private:
    Texture texture;
    Sprite sprite;

    float movementSpeed;

    void initTexture();
    void initSprite();

public:
    Player();
    virtual ~Player();

    void move(const float dirY);
    void update();
    void render(RenderTarget& target);

};


#endif //PROYECTO1_BATTLESPACE_PLAYER_H
