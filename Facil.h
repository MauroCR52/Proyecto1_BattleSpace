#ifndef PROYECTO1_BATTLESPACE_FACIL_H
#define PROYECTO1_BATTLESPACE_FACIL_H
#include <map>
#include <string>
#include <sstream>
#include <boost/asio.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyR.h"
#include "Collector.h"

using namespace sf;
using namespace std;

class Facil {
private:

    map<string, Texture *> textures;
    vector<Bullet *> bullets;

    RenderWindow *window;
    Player *player;

    Font font;
    Text bulletsCont;
    Text collectorCont;
    Text enemiesRest;
    Text oleadaCont;
    Text pointsCont;

    //boost::asio::io_service io;
    //boost::asio::serial_port port = boost::asio::serial_port(io, "/dev/ttyACM0");
    string input;

    Texture backgroundTex;
    Sprite background;

    Clock clock; //clock para estrategias

    unsigned balas;
    unsigned puntos;
    unsigned cant_enemigos;
    unsigned oleadas;
    unsigned collector;
    unsigned totalEnemies;

    float spawnTimer;
    float spawnTimerMax;

    float delayTimer;
    float delayTimerMax;

    float spawnTimerR;
    float spawnTimerMaxR;

    bool delay;
    bool canSpawn;

    //para los paged power
    bool shootFaster = false;
    bool moveFaster = false;
    bool freezeEnemies = false;
    bool regenerateBullets = false;
    float elapsedTime = 0.f;
    bool shootFasterKeyPressed = false;
    bool wkeyPressed = false;

    vector<Enemy*> enemies;
    vector<EnemyR*> enemiesR;

    void initWindow();
    void initTextures();
    void initBulletGUI();
    void initBulletCollectorGUI();
    void initPointGUI();
    void initCantEnemies();
    void initOleadasGUI();
    void initBackground();
    void initSystems();
    void initDelay();
    void initPlayer();
    void initEnemies();
    void initEnemiesR();

public:
    Facil();
    virtual ~Facil();

    void run();
    void updatePollEvents();

    //void updateArduino();

    void updateInput();
    void updateGUI();
    void updateBackground();
    void updateCollision();
    void updateBullets();
    void updateEnemiesAndCombat();
    void updateEnemiesRAndCombat();
    void updateDelay();
    void update();
    void renderGUI();
    void renderBackground();
    void render();

};


#endif //PROYECTO1_BATTLESPACE_FACIL_H
