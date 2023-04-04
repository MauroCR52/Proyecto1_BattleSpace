#ifndef PROYECTO1_BATTLESPACE_MEDIO_H
#define PROYECTO1_BATTLESPACE_MEDIO_H
#include "Player.h"

using namespace sf;

class Medio {
private:
    RenderWindow* window;
    Font font;

    void initWindow();

public:
    Medio();
    virtual ~Medio();

    void run();
    void update();
    void render();

};


#endif //PROYECTO1_BATTLESPACE_MEDIO_H