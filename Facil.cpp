#include "iostream"
#include "Facil.h"

void Facil::initWindow() {
    this->window = new RenderWindow(VideoMode(800, 600), "Facil - Battlespace", Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

Facil::Facil() {
    this->initWindow();
    this->initTextures();
    this->initPlayer();
}

Facil::~Facil() {
    delete this->window;
    delete this->player;
}

void Facil::run() {
    while (this->window->isOpen()){
        this->update();
        this->render();
    }
}

void Facil::update() {

    this->updatePollEvents();
    this->updateInput();
    this->updateBullets();

}

void Facil::render() {
    this->window->clear(Color(137, 155, 176, 255));
    //Enseña las varas
    this->player->render(*this->window);
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

    for (auto *bullet : this->bullets){

        bullet->update();

    }

}

