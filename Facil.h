#ifndef PROYECTO1_BATTLESPACE_FACIL_H
#define PROYECTO1_BATTLESPACE_FACIL_H
#include<map>
#include "Player.h"
using namespace sf;
using namespace std;

class Facil {
private:
    RenderWindow* window;
    Player* player;

    Font font;
    void initWindow();
    void initTextures();
    void initPlayer();

public:
    Facil();
    virtual ~Facil();

    void run();
    void update();
    void render();

};


#endif //PROYECTO1_BATTLESPACE_FACIL_H
