#include "iostream"
#include "Facil.h"
#include "Bullet.h"
#include <chrono>
#include <thread>

void Facil::initWindow() {
    this->window = new RenderWindow(VideoMode(800, 600), "Facil - Battlespace", Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

Facil::Facil() {
    this->initWindow();
    this->initTextures();
    this->initBulletGUI();
    this->initBulletCollectorGUI();
    this->initPlayer();
    this->initEnemies();
    this->initEnemiesR();

}

Facil::~Facil() {
    delete this->window;
    delete this->player;

    for (auto &i : this->textures){
        delete i.second;
    }

    for (auto *i : this->bullets){
        delete i;
    }

    for (auto *i : this->enemies){
        delete i;
    }
    for (auto *i : this->enemiesR){
        delete i;
    }

}

void Facil::run() {
    while (this->window->isOpen()){
        this->update();
        this->render();
    }
}

void Facil::updatePollEvents(){
    Event e;
    while (this->window->pollEvent(e)) {
        if(e.Event::type == Event::Closed)
            this->window->close();
        if (e.Event::key.code == Keyboard::Escape)
            this->window->close();
    }


}

void Facil::updateInput(){
    // Mover el jugador
    if(Keyboard::isKeyPressed(Keyboard::Up))
        this->player->move(-1.f);
    if(Keyboard::isKeyPressed(Keyboard::Down))
        this->player->move(1.f);
    if (this->window->isOpen() && this->player->canAttack()){
        this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPost().x, this->player->getPost().y + 18.f, 1.f, 0.f,5.f));
    }

    //estrategia 1
    if (Keyboard::isKeyPressed(Keyboard::Q)){
        shootFaster = true;
        this->player->setAttackCooldownMax(40.f);
        //arreglarlo para que sea de acuerdo a la velocidad de la bala
    }

    //estrategia 2
    if (Keyboard::isKeyPressed(Keyboard::W)){
        moveFaster = true;
        this->player->setMovementSpeed(7.f);
        //durante 5 segundos y que vuelva a la velocidad normal
    }

    //estrategia 3
    if (Keyboard::isKeyPressed(Keyboard::E)){
        freezeEnemies = true;
        //poner la posicion de los enemigos estatica
        //pasen 5 segundos y que vuelva a la normalidad
    }

    //estrategia 4
    if (Keyboard::isKeyPressed(Keyboard::R)){
        regenerateBullets = true;
        //poner el counter de balas desde 0
        //durante 5 segundos y que vuelva a la velocidad normal
    }

    //reiniciar las estrategias luego de 5 segundos
    //shootFaster = false;
    //moveFaster = false;
    //freezeEnemies = false;
    //regenerateBullets = false;

}

void Facil::update() {

    this->updatePollEvents();
    this->updateInput();
    this->player->update();
    this->updateBullets();
    this->updateEnemiesAndCombat();
    this->updateEnemiesRAndCombat();
    this->updateGUI();
}

void Facil::render() {
    this->window->clear(Color(137, 155, 176, 255));
    //Enseña las varas
    this->player->render(*this->window);

    for (auto *bullet : this->bullets){
        bullet->render(this->window);

    }
    for (auto *enemy : this->enemies){
        enemy->render(*this->window);
    }
    for (auto *enemyR : this->enemiesR){
        enemyR->render(*this->window);
    }

    this->renderGUI();
    this->window->display();

}

void Facil::initPlayer() {
    this->player = new Player();
}


void Facil::initTextures() {

    this->textures["BULLET"] = new Texture();
    this->textures["BULLET"]->loadFromFile("/home/mauluna52/CLionProjects/Proyecto1_BattleSpace/Textures/firebullet.png");

}

void Facil::updateBullets() {
    unsigned  counter = 0;
    for (auto *bullet : this->bullets){
        bullet->update();

        //Bullet culling right screen
        if (bullet->getBounds().left + bullet->getBounds().width > 800.f)
        {
            // Modificar para en vez de borrar, se vaya al collector
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin() + counter);
            --counter;
            //cout << this->bullets.size() << endl;
        }
        ++counter;
    }

}

void Facil::initEnemies() {
    this->spawnTimerMax = 180.f;
    this->spawnTimer = this->spawnTimerMax;
}

void Facil::initEnemiesR() {
    this->spawnTimerMaxR = 500.f;
    this->spawnTimerR = this->spawnTimerMaxR;

}

void Facil::updateEnemiesRAndCombat() {
    this->spawnTimerR += 0.5f;
    if (this->spawnTimerR >= this->spawnTimerMaxR){
        this->enemiesR.push_back(new EnemyR(800.f, rand() % this->window->getSize().y-60.f));
        this->spawnTimerR = 0.f;

    }
    for (int i = 0; i < this->enemiesR.size(); ++i) {
        bool enemy_removed = false;
        this->enemiesR[i]->update();

        for (size_t k = 0; k < this->bullets.size() && !enemy_removed; k++) {
            if (this->bullets[k]->getBounds().intersects(this->enemiesR[i]->getBounds())) {
                this->bullets.erase(this->bullets.cbegin() + k);
                this->enemiesR.erase(this->enemiesR.cbegin() + i);
                enemy_removed = true;
            }
        }

        if(!enemy_removed){
            // Remover nave cuando llega al otro lado de la ventana (Implementar buzzer de arduino)
            if (this->enemiesR[i]->getBounds().left < 0.f)
            {
                //Enviar mensaje a Arduino
                this->enemiesR.erase(this->enemiesR.cbegin() + i);
                std::cout << this->enemiesR.size() << endl;
            }
            if (this->enemiesR[i]->getBounds().top < 0.f && this->enemiesR[i]->getMoveY() < 0){
                this->enemiesR[i]->setMoveY(1.5f);
            }
            if (this->enemiesR[i]->getBounds().top > 540.f && this->enemiesR[i]->getMoveY() > 0){
                this->enemiesR[i]->setMoveY(-1.5f);
            }
        }
    }
}
void Facil::updateEnemiesAndCombat() {

    this->spawnTimer += 0.5f;
    if (this->spawnTimer >= this->spawnTimerMax){
        this->enemies.push_back(new Enemy(800.f, rand() % 550));
        this->spawnTimer = 0.f;
    }

    for (int i = 0; i < this->enemies.size(); ++i) {
        bool enemy_removed = false;
        this->enemies[i]->update();

        for (size_t k = 0; k < this->bullets.size() && !enemy_removed; k++) {
            if (this->bullets[k]->getBounds().intersects(this->enemies[i]->getBounds())) {
                this->bullets.erase(this->bullets.cbegin() + k);
                this->enemies.erase(this->enemies.cbegin() + i);
                enemy_removed = true;
            }
        }
        if(!enemy_removed){
            // Remover nave cuando llega al otro lado de la ventana (Implementar buzzer de arduino)
            if (this->enemies[i]->getBounds().left < 0.f)
            {
                //Enviar mensaje a Arduino
                this->enemies.erase(this->enemies.cbegin() + i);
                std::cout << this->enemies.size() << endl;
            }

        }
    }
}

void Facil::initBulletGUI() {
    if (!this->font.loadFromFile("/home/mauluna52/CLionProjects/Proyecto1_BattleSpace/fonts/ChakraPetch-Regular.ttf"))
        std::cout << "ERROR::GAME::Failed to load font" << endl;

    this->bulletsCont.setFont(this->font);
    this->bulletsCont.setCharacterSize(25);
    this->bulletsCont.setFillColor(Color::Red);
    this->bulletsCont.setString("test");

}

void Facil::initBulletCollectorGUI() {
    if (!this->font.loadFromFile("/home/mauluna52/CLionProjects/Proyecto1_BattleSpace/fonts/ChakraPetch-Regular.ttf"))
        std::cout << "ERROR::GAME::Failed to load font" << endl;
    this->collectorCont.setFont(this->font);
    this->collectorCont.setCharacterSize(25);
    this->collectorCont.setFillColor(Color::Red);
    this->collectorCont.setString("test");

}

void Facil::updateGUI() {

}

void Facil::renderGUI() {
    this->window->draw(this->bulletsCont);
    this->window->draw(this->collectorCont);
}
