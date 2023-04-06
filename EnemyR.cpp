//
// Created by mauluna52 on 5/04/23.
//

#include "EnemyR.h"
using namespace std;

EnemyR::EnemyR(float pos_x, float pos_y) {
    this->initVariables();
    this->initTexture();
    this->initSprite();

    this->sprite.setPosition(pos_x, pos_y);
}

EnemyR::~EnemyR() {

}


void EnemyR::initVariables() {
    this->type = 0;
    this->hpMax = 10;
    this->hp = 0;
    this->damage = 1;
    this->points = 5;

}

void EnemyR::initTexture() {
    if(!this->texture.loadFromFile("/home/mauluna52/CLionProjects/Proyecto1_BattleSpace/Textures/redenemy.png")){
        cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << endl;
    }

}

void EnemyR::initSprite() {
    this->sprite.setTexture(this->texture);
    this->sprite.scale(0.1f, 0.1f);
}

void EnemyR::render(RenderTarget &target) {
    target.draw(this->sprite);
}

const Vector2f &EnemyR::getPost() const {
    return this->sprite.getPosition();
}

void EnemyR::update() {

    this->sprite.move(-1.f, move_y);
}

const FloatRect EnemyR::getBounds() const {
    return this->sprite.getGlobalBounds();
}

void EnemyR::setMoveY(float moveY) {
    move_y = moveY;
}

float EnemyR::getMoveY() const {
    return move_y;
}

