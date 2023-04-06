//#include "iostream"
#include "Player.h"

using namespace std;

Player::Player() {
    this->initVariables();
    this->initTexture();
    this->initSprite();
}

Player::~Player() {

}

void Player::update() {
    this->updateAttack();
}

void Player::render(RenderTarget& target) {
    target.draw(this->sprite);
}

void Player::initTexture() {
    //Cargamos la imagen del jugador

    if(!this->texture.loadFromFile("/home/mauluna52/CLionProjects/Proyecto1_BattleSpace/Textures/player.png")){
        cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << endl;
    }
}

void Player::initSprite() {
    this->sprite.setTexture(this->texture);
    this->sprite.scale(0.1f, 0.1f);
}

void Player::move(const float dirY) {
    this->sprite.move(0, this->movementSpeed * dirY);
}

void Player::updateAttack() {

    if (this->attackCooldown < this->attackCooldownMax);
    this->attackCooldown += 0.5f;
}

const bool Player::canAttack() {
    if (this->attackCooldown >= this->attackCooldownMax){
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
}

void Player::initVariables() {
    this->movementSpeed = 2.f;
    this->attackCooldownMax = 10.f;
    this->attackCooldown = this->attackCooldownMax;
}

const Vector2f &Player::getPost() const {
    return this->sprite.getPosition();
}