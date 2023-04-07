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
    this->attackCooldownMax = 60.f;
    this->attackCooldown = this->attackCooldownMax;
    this->damage = 10;
}

const Vector2f &Player::getPost() const {
    return this->sprite.getPosition();
}

const FloatRect Player::getBounds() const {
    return this->sprite.getGlobalBounds();
}

void Player::setMovementSpeed(float movementSpeed) {
    Player::movementSpeed = movementSpeed;
}

void Player::setAttackCooldownMax(float AttackCooldownMax) {
    Player::attackCooldownMax = AttackCooldownMax;

}

void Player::setPosition(const Vector2f pos) {
    this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

int Player::getDamage() {
    return damage;
}

void Player::setDamage(int Dmg) {
    damage = Dmg;
}

