#ifndef PROYECTO1_BATTLESPACE_MEDIO_H
#define PROYECTO1_BATTLESPACE_MEDIO_H
#include "Player.h"

using namespace sf;

class Medio {
private:
    RenderWindow* window;
    Player* player;

    Font font;
    void initWindow();
    void initPlayer();

public:
    Medio();
    virtual ~Medio();

    void run();
    void updatePollEvents();
    void updateInput();
    void update();
    void render();

};


#endif //PROYECTO1_BATTLESPACE_MEDIO_H