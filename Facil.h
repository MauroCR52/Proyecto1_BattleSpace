#ifndef PROYECTO1_BATTLESPACE_FACIL_H
#define PROYECTO1_BATTLESPACE_FACIL_H
#include<map>
#include "Player.h"
#include "Bullet.h"

using namespace sf;
using namespace std;

class Facil {
private:

    map <string, Texture*> textures;
    vector<Bullet*> bullets;

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
    void updatePollEvents();
    void updateInput();
    void updateBullets();
    void update();
    void render();

};


#endif //PROYECTO1_BATTLESPACE_FACIL_H
