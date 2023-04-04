//#include "iostream"
#include "Player.h"

using namespace std;

Player::Player() {
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
    /*
    if(!this->texture.loadFromFile("/Textures/player.png")){
        cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << endl;
    }
     */
}
void Player::initSprite() {
    this->sprite.setTexture(this->texture);


}

