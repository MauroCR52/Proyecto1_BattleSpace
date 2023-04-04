//#include "iostream"
#include "Player.h"

using namespace std;

Player::Player() {

    this->movementSpeed = 2.f;
    this->initTexture();
    this->initSprite();
}

Player::~Player() {

}

//Funciones
void Player::update() {

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

const Vector2f &Player::getPost() const {
    return this->sprite.getPosition();
}

