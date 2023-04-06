#include "Bullet.h"
#include "Collector.h"
Bullet::Bullet(){
}

Bullet::Bullet(Texture * texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed) {
    this->shape.setTexture(*texture);
    this->shape.setPosition(pos_x, pos_y);
    this->shape.scale(0.5f, 0.5f);
    this->direction.x = dir_x;
    this->direction.y = dir_y;
    this->movementSpeed = movement_speed;
}

Bullet::~Bullet(){
}

void Bullet::update() {
    this->shape.move(this->movementSpeed * this->direction);

}

void Bullet::render(RenderTarget *target) {
    target->draw(this->shape);
}

const FloatRect Bullet::getBounds() const {
    return this->shape.getGlobalBounds();
}

void Bullet::setReciclaje(Collector *collector) {
    reciclaje = collector;
}

void Bullet::operator delete(void *p) {
    Bullet* nodeToDelete = static_cast<Bullet*>(p);
    if (reciclaje != nullptr){
        reciclaje->insertNode(nodeToDelete);
    }
    else{
        ::operator delete(nodeToDelete);
    }
}

Collector* Bullet::reciclaje = nullptr;