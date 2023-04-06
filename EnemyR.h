//
// Created by mauluna52 on 5/04/23.
//

#ifndef PROYECTO1_BATTLESPACE_ENEMYR_H
#define PROYECTO1_BATTLESPACE_ENEMYR_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cstdlib>

#include "iostream"
using namespace sf;

class EnemyR {
private:
    Texture texture;
    Sprite sprite;

    int type;
    int hp;
    int hpMax;
    int damage;
    int points;

    float move_y = (rand() % 2 == 0) ? 1.5f : -1.5f;

    void initVariables();
    void initTexture();
    void initSprite();


public:
    EnemyR(float pos_x, float pos_y);
    virtual ~EnemyR();

    const FloatRect getBounds() const;

    const Vector2f& getPost() const;

    void update();
    void render(RenderTarget& target);
    void setMoveY(float moveY);
    float getMoveY() const;

};


#endif //PROYECTO1_BATTLESPACE_ENEMYR_H
