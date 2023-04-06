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

    float attackCooldown;
    float attackCooldownMax;

    void initVariables();
    void initTexture();
    void initSprite();

public:
    Player();
    virtual ~Player();

    const Vector2f& getPost() const;

    void move(const float dirY);
    const bool canAttack();

    void updateAttack();
    void update();
    void render(RenderTarget& target);

};


#endif //PROYECTO1_BATTLESPACE_PLAYER_H
