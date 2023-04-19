#ifndef PROYECTO1_BATTLESPACE_BULLET_H
#define PROYECTO1_BATTLESPACE_BULLET_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System/Clock.hpp>
#include "iostream"

using namespace sf;
using namespace std;

class Collector;

class Bullet {
    friend class Collector;

private:

    Sprite shape;

    Vector2f direction;
    float movementSpeed;

    Bullet* next;

public:
    Bullet();
    Bullet(Texture * texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
    virtual ~Bullet();

    const FloatRect getBounds() const;

    void update();
    void render(RenderTarget* target);
    static Collector* reciclaje;

    static void setReciclaje(Collector* collector);

    void operator delete(void* p);
    void* operator new(size_t size);

};

#endif //PROYECTO1_BATTLESPACE_BULLET_H