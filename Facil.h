#ifndef PROYECTO1_BATTLESPACE_FACIL_H
#define PROYECTO1_BATTLESPACE_FACIL_H
#include <map>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyR.h"
#include "Collector.h"

using namespace sf;
using namespace std;

class Facil {
private:

    map <string, Texture*> textures;
    vector<Bullet*> bullets;

    RenderWindow* window;
    Player* player;

    Font font;
    Text bulletsCont;
    Text collectorCont;

    float spawnTimer;
    float spawnTimerMax;

    float spawnTimerR;
    float spawnTimerMaxR;

    //para los paged power
    bool shootFaster = false;
    bool moveFaster = false;
    bool freezeEnemies = false;
    bool regenerateBullets = false;

    vector<Enemy*> enemies;
    vector<EnemyR*> enemiesR;

    void initWindow();
    void initTextures();
    void initBulletGUI();
    void initBulletCollectorGUI();
    void initPlayer();
    void initEnemies();
    void initEnemiesR();

public:
    Facil();
    virtual ~Facil();

    void run();
    void updatePollEvents();
    void updateInput();
    void updateGUI();
    void updateBullets();
    void updateEnemiesAndCombat();
    void updateEnemiesRAndCombat();
    void update();
    void renderGUI();
    void render();

};


#endif //PROYECTO1_BATTLESPACE_FACIL_H
