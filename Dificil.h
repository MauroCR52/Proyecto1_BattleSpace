#ifndef PROYECTO1_BATTLESPACE_DIFICIL_H
#define PROYECTO1_BATTLESPACE_DIFICIL_H

#include "Player.h"
using namespace sf;

class Dificil {
private:
    RenderWindow* window;
    Font font;

    void initWindow();

public:
    Dificil();
    virtual ~Dificil();

    void run();
    void update();
    void render();

};


#endif //PROYECTO1_BATTLESPACE_DIFICIL_H