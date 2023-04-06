//
// Created by mauluna52 on 5/04/23.
//

#ifndef PROYECTO1_BATTLESPACE_ENEMY_H
#define PROYECTO1_BATTLESPACE_ENEMY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "iostream"

using namespace sf;

class Enemy {
private:
    Texture texture;
    Sprite sprite;

    int type;
    int hp;
    int hpMax;
    int damage;
    int points;

    void initVariables();
    void initTexture();
    void initSprite();


public:
    Enemy(float pos_x, float pos_y);
    virtual ~Enemy();

    const FloatRect getBounds() const;

    const Vector2f& getPost() const;

    void update();
    void render(RenderTarget& target);


};


#endif //PROYECTO1_BATTLESPACE_ENEMY_H
