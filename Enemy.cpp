//
// Created by mauluna52 on 5/04/23.
//

#include "Enemy.h"
using namespace std;

Enemy::Enemy(float pos_x, float pos_y) {
    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->sprite.setPosition(pos_x, pos_y);

}

Enemy::~Enemy() {

}


void Enemy::initVariables() {
    this->hp = 10;
}

void Enemy::initTexture() {
    if(!this->texture.loadFromFile("/home/mauluna52/CLionProjects/Proyecto1_BattleSpace/Textures/greenenemy.png")){
        cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << endl;
    }

}

void Enemy::initSprite() {
    this->sprite.setTexture(this->texture);
    this->sprite.scale(0.1f, 0.1f);
}

void Enemy::render(RenderTarget &target) {
    target.draw(this->sprite);
}

const Vector2f &Enemy::getPost() const {
    return this->sprite.getPosition();
}

void Enemy::update() {
    this->sprite.move(-1.f, 0.f);
}

const FloatRect Enemy::getBounds() const {
    return this->sprite.getGlobalBounds();
}
int Enemy::gethp() {
    return hp;
}

void Enemy::setHp(int Hp) {
    hp = Hp;
}

