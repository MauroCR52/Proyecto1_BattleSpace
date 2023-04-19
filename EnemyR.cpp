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
    this->hp = 10;
}

void EnemyR::initTexture() {
    if(!this->texture.loadFromFile("/home/fernandez/datos2/Proyecto1_BattleSpace/Textures/redenemy.png")){
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

int EnemyR::gethp() {
    return hp;
}

void EnemyR::setHp(int Hp) {
    hp = Hp;
}

