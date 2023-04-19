#include "Dificil.h"
#include "Menu.h"
#include "iostream"
#include "Bullet.h"
#include <chrono>
#include <thread>

void Dificil::initWindow() {
    this->window = new RenderWindow(VideoMode(800, 600), "Dificil - Battlespace", Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

Dificil::Dificil() {
    this->initWindow();
    this->initPlayer();
    this->initTextures();
    this->initBulletGUI();
    this->initBulletCollectorGUI();
    this->initPointGUI();
    this->initOleadasGUI();
    this->initCantEnemies();
    this->initBackground();
    this->initSystems();
    this->initDelay();
    this->initEnemies();
    this->initEnemiesR();

}

Dificil::~Dificil() {
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

void Dificil::run() {
    while (this->window->isOpen()){
        if (this->oleadas <= 5){
            this->update();
        }
        this->render();
    }
}

void Dificil::update() {

    //this->updateArduino();

    this->updatePollEvents();
    this->updateInput();
    this->updateDelay();
    this->player->update();
    this->updateCollision();
    this->updateBullets();
    this->updateEnemiesAndCombat();
    this->updateEnemiesRAndCombat();
    this->updateGUI();
    this->updateBackground();
}

void Dificil::render() {
    this->window->clear(Color(137, 155, 176, 255));

    this->renderBackground();

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


void Dificil::initPlayer() {
    this->player = new Player();
}

void Dificil::initTextures() {

    this->textures["BULLET"] = new Texture();
    this->textures["BULLET"]->loadFromFile("/home/fernandez/datos2/Proyecto1_BattleSpace/Textures/firebullet.png");

}

void Dificil::updateBullets() {
    unsigned  counter = 0;
    for (auto *bullet : this->bullets){
        bullet->update();

        //Bullet culling right screen
        if (bullet->getBounds().left + bullet->getBounds().width > 800.f)
        {
            if (this->balas != 0){
                // Modificar para en vez de borrar, se vaya al collector
                delete this->bullets.at(counter);
                this->bullets.erase(this->bullets.begin() + counter);
                --counter;
                this->collector += 1;
            } else {
                ::delete this->bullets.at(counter);
                this->bullets.erase(this->bullets.begin() + counter);
                --counter;
            }
        }
        ++counter;
    }
}

void Dificil::updatePollEvents() {
    Event e;
    while (this->window->pollEvent(e)) {
        if(e.Event::type == Event::Closed)
            this->window->close();
        if (e.Event::key.code == Keyboard::Escape)
            this->window->close();
        if (this->collector == 0 && this->oleadas == 5){
            this->window->close();
            Menu menu;
            menu.run();}
    }
    if (this->balas == 0){
        this->player->setDamage(5);
    }
}

void Dificil::updateInput() {
    if (this->oleadas == 1){
        char soundAction = '1';
        //boost::asio::write(port, boost::asio::buffer(&soundAction, 1));
    }

    // Mover el jugador
    if(Keyboard::isKeyPressed(Keyboard::Up))
        this->player->move(-1.f);
    if(Keyboard::isKeyPressed(Keyboard::Down))
        this->player->move(1.f);

    if (!this->delay){
        if (this->balas != 0){
            if (this->window->isOpen() && this->player->canAttack()){
                this->bullets.push_back(::new Bullet(this->textures["BULLET"], this->player->getPost().x, this->player->getPost().y + 18.f, 1.f, 0.f,9.f));
                this->balas--;
            }
        }
        if (this->balas == 0 && this->collector != 0){
            if (this->window->isOpen() && this->player->canAttack()){
                this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPost().x, this->player->getPost().y + 18.f, 1.f, 0.f,9.f));
                this->collector--;
            }
        }
    }
}

void Dificil::initDelay() {
    this->delayTimerMax = 200.f;
    this->delayTimer = 0.f;
}

void Dificil::initEnemies() {
    this->spawnTimerMax = 200.f;
    this->spawnTimer = this->spawnTimerMax;
}

void Dificil::initEnemiesR() {
    this->spawnTimerMaxR = 600.f;
    this->spawnTimerR = 500.f;

}

void Dificil::updateEnemiesRAndCombat() {
    //Aparicion de enemigos
    if (this->canSpawn){
        if (this->cant_enemigos != 0){
            this->spawnTimerR += 0.9f;
            if (this->spawnTimerR >= this->spawnTimerMaxR){
                this->enemiesR.push_back(new EnemyR(800.f, rand() % this->window->getSize().y-60.f));
                this->cant_enemigos--;
                this->spawnTimerR = 0.9f;
            }
        }
    }
    //Borrar enemigos
    for (int i = 0; i < this->enemiesR.size(); ++i) {
        bool enemy_removed = false;
        this->enemiesR[i]->update();

        for (size_t k = 0; k < this->bullets.size() && !enemy_removed; k++) {
            if (this->bullets[k]->getBounds().intersects(this->enemiesR[i]->getBounds())) {
                this->enemiesR[i]->setHp(this->enemiesR[i]->gethp()-this->player->getDamage());
                if (this->enemiesR[i]->gethp() <= 0){
                    this->bullets.erase(this->bullets.cbegin() + k);
                    this->enemiesR.erase(this->enemiesR.cbegin() + i);
                    this->puntos++;
                    enemy_removed = true;
                }
                else {
                    this->bullets.erase(this->bullets.cbegin() + k);
                }
            }
        }
        if(!enemy_removed){
            // Remover nave cuando llega al otro lado de la ventana (Implementar buzzer de arduino)
            if (this->enemiesR[i]->getBounds().left < 0.f)
            {
                //Enviar mensaje a Arduino
                this->enemiesR.erase(this->enemiesR.cbegin() + i);
                char soundAction = 'S';
                //boost::asio::write(port, boost::asio::buffer(&soundAction, 1));

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
void Dificil::updateEnemiesAndCombat() {
    //Aparicion de enemigos
    if (this->canSpawn){
        if (this->cant_enemigos != 0){
            this->spawnTimer += 0.9f;
            if (this->spawnTimer >= this->spawnTimerMax){
                this->enemies.push_back(new Enemy(800.f, rand() % 550));
                this->cant_enemigos--;
                this->spawnTimer = 0.9f;
            }
        }
    }
    // Borrar enemigos
    for (int i = 0; i < this->enemies.size(); ++i) {
        bool enemy_removed = false;
        this->enemies[i]->update();

        for (size_t k = 0; k < this->bullets.size() && !enemy_removed; k++) {
            if (this->bullets[k]->getBounds().intersects(this->enemies[i]->getBounds())) {
                this->enemies[i]->setHp(this->enemies[i]->gethp()-this->player->getDamage());
                if (this->enemies[i]->gethp() <= 0){
                    this->bullets.erase(this->bullets.cbegin() + k);
                    this->enemies.erase(this->enemies.cbegin() + i);
                    this->puntos++;
                    enemy_removed = true;
                }
                else {
                    this->bullets.erase(this->bullets.cbegin() + k);
                }
            }
        }
        if(!enemy_removed){
            // Remover nave cuando llega al otro lado de la ventana (Implementar buzzer de arduino)
            if (this->enemies[i]->getBounds().left < 0.f)
            {
                //Enviar mensaje a Arduino
                this->enemies.erase(this->enemies.cbegin() + i);
                char soundAction = 'S';
                //boost::asio::write(port, boost::asio::buffer(&soundAction, 1));
            }
        }
    }
}

void Dificil::initBulletGUI() {
    if (!this->font.loadFromFile("/home/fernandez/datos2/Proyecto1_BattleSpace/fonts/ChakraPetch-Regular.ttf"))
        std::cout << "ERROR::GAME::Failed to load font" << endl;

    this->bulletsCont.setFont(this->font);
    this->bulletsCont.setCharacterSize(25);
    this->bulletsCont.setFillColor(Color::Red);
    this->bulletsCont.setString("test");

}

void Dificil::initBulletCollectorGUI() {
    if (!this->font.loadFromFile("/home/fernandez/datos2/Proyecto1_BattleSpace/fonts/ChakraPetch-Regular.ttf"))
        std::cout << "ERROR::GAME::Failed to load font" << endl;
    this->collectorCont.setFont(this->font);
    this->collectorCont.setCharacterSize(25);
    this->collectorCont.setFillColor(Color::Red);
    this->collectorCont.setPosition(600.f, 0.f);
    this->collectorCont.setString("test");

}
void Dificil::initPointGUI() {
    if (!this->font.loadFromFile("/home/fernandez/datos2/Proyecto1_BattleSpace/fonts/ChakraPetch-Regular.ttf"))
        std::cout << "ERROR::GAME::Failed to load font" << endl;
    this->pointsCont.setFont(this->font);
    this->pointsCont.setCharacterSize(25);
    this->pointsCont.setFillColor(Color::Red);
    this->pointsCont.setPosition(670.f, 560.f);
    this->pointsCont.setString("test");

}

void Dificil::initCantEnemies() {
    if (!this->font.loadFromFile("/home/fernandez/datos2/Proyecto1_BattleSpace/fonts/ChakraPetch-Regular.ttf"))
        std::cout << "ERROR::GAME::Failed to load font" << endl;
    this->enemiesRest.setFont(this->font);
    this->enemiesRest.setCharacterSize(25);
    this->enemiesRest.setFillColor(Color::Red);
    this->enemiesRest.setPosition(600.f, 30.f);
    this->enemiesRest.setString("test");

}

void Dificil::initOleadasGUI() {
    if (!this->font.loadFromFile("/home/fernandez/datos2/Proyecto1_BattleSpace/fonts/ChakraPetch-Regular.ttf"))
        std::cout << "ERROR::GAME::Failed to load font" << endl;
    this->oleadaCont.setFont(this->font);
    this->oleadaCont.setCharacterSize(25);
    this->oleadaCont.setFillColor(Color::Red);
    this->oleadaCont.setPosition(600.f, 60.f);
    this->oleadaCont.setString("test");

}

void Dificil::updateGUI() {
    stringstream ss, cc, pp, ee, oo;
    ss << "Balas: " << this->balas;
    cc << "Collector: " << this->collector;
    pp << "Puntos: " << this->puntos;
    ee << "Enemigos: " << this->cant_enemigos;
    oo << "Oleada: " << this->oleadas;
    this->bulletsCont.setString(ss.str());
    this->collectorCont.setString(cc.str());
    this->pointsCont.setString(pp.str());
    this->enemiesRest.setString(ee.str());
    this->oleadaCont.setString(oo.str());

}

void Dificil::renderGUI() {
    this->window->draw(this->bulletsCont);
    this->window->draw(this->collectorCont);
    this->window->draw(this->pointsCont);
    this->window->draw(this->oleadaCont);
    this->window->draw(this->enemiesRest);
}

void Dificil::initBackground() {
    if (!this->backgroundTex.loadFromFile("/home/fernandez/datos2/Proyecto1_BattleSpace/Textures/night_sky.jpg")){
        cout << "ERROR::FACIL::COULD NOT LOAD BACKGROUND TEXTURE" << endl;
    }
    this->background.setTexture(this->backgroundTex);
    this->background.scale(1.f, 1.f);
}

void Dificil::renderBackground() {
    this->window->draw(this->background);
}

void Dificil::updateBackground() {

}

void Dificil::updateCollision() {
    // Colision con el borde superior de la pantalla
    if (this->player->getBounds().top < 0.f){
        this->player->setPosition(this->player->getBounds().left, 0.f);
    }
        // Colision con el borde inferior de la pantalla
    else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y){
        this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
    }
}

void Dificil::initSystems() {
    //this->port.set_option(boost::asio::serial_port_base::baud_rate(9600));
    this->cant_enemigos = 20;
    this->oleadas = 1;
    this->balas = 130;
    this->collector = 0;
    this->totalEnemies = 20;
    this->puntos = 0;
    this->delay = false;
    this->canSpawn = true;
}

void Dificil::updateDelay() {
    if (this->cant_enemigos == 0){
        this->canSpawn = false;
        if(enemiesR.empty() && enemies.empty()){
            this->delay = true;
            this->delayTimer += 0.5f;
            if (this->delayTimer >= this->delayTimerMax){
                this->delay = false;
                this->canSpawn = true;
                this->oleadas++;

                /**
                if (this->oleadas == 2){
                    char soundAction = '2';
                    boost::asio::write(port, boost::asio::buffer(&soundAction, 1));
                }
                if (this->oleadas == 3){
                    char soundAction = '3';
                    boost::asio::write(port, boost::asio::buffer(&soundAction, 1));
                }
                if (this->oleadas == 4){
                    char soundAction = '4';
                    boost::asio::write(port, boost::asio::buffer(&soundAction, 1));
                }
                if (this->oleadas == 5){
                    char soundAction = '5';
                    boost::asio::write(port, boost::asio::buffer(&soundAction, 1));
                }
                */
                this->totalEnemies += 3;
                this->cant_enemigos = this->totalEnemies;
                cout << "Comienza nueva oleada" << endl;
                this->delayTimer = 0.f;
            }
        }
    }
}
/**
void Medio::updateArduino() {
    boost::asio::streambuf buffer;
    boost::asio::read_until(port, buffer, '\n');
    std::string message;
    std::istream input_stream(&buffer);
    std::getline(input_stream, message);
    if (message.find("0") != string::npos){
        this->player->setAttackCooldownMax(60.f);
    }
    else if (message.find("1") != string::npos){
        this->player->setAttackCooldownMax(54.f);
    }
    else if (message.find("2") != string::npos){
        this->player->setAttackCooldownMax(48.f);
    }
    else if (message.find("3") != string::npos){
        this->player->setAttackCooldownMax(42.f);
    }
    else if (message.find("4") != string::npos){
        this->player->setAttackCooldownMax(36.f);
    }
    else if (message.find("5") != string::npos){
        this->player->setAttackCooldownMax(30.f);
    }
    else if (message.find("6") != string::npos){
        this->player->setAttackCooldownMax(24.f);
    }
    else if (message.find("7") != string::npos){
        this->player->setAttackCooldownMax(18.f);
    }
    else if (message.find("8") != string::npos){
        this->player->setAttackCooldownMax(12.f);
    }
    else if (message.find("9") != string::npos){
        this->player->setAttackCooldownMax(6.f);
    }
    else if (message.find("U") != string::npos){
        this->player->move(-1.f);
    }
    else if (message.find("D") != string::npos){
        this->player->move(1.f);
    }

}
*/
