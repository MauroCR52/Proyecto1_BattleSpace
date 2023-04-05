#include "iostream"
#include "Facil.h"
#include <SFML/Graphics.hpp>

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

    for (auto &i : this->textures){
        delete i.second;
    }

    for (auto *i : this->bullets){
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

    this->bullets.push_back(
            new Bullet(this->textures["BULLET"], this->player->getPost().x, this->player->getPost().y, 50.f, 0.f, 2.f));


}

void Facil::update() {

    this->updatePollEvents();
    this->updateInput();
    this->updateBullets();
}

void Facil::render() {
    this->window->clear(Color(137, 155, 176, 255));
    this->player->render(*this->window);
    for (auto *bullet : this->bullets){
        bullet->render(this->window);
    }
    this->window->display();
}

void Facil::initPlayer() {
    this->player = new Player();
}

void Facil::initTextures() {
    this->textures["BULLET"] = new Texture();
    this->textures["BULLET"]->loadFromFile("/home/fernandez/datos2/Proyecto1_BattleSpace/Textures/firebullet.png");

}

void Facil::updateBullets() {

    for (auto *bullet : this->bullets){

        bullet->update();

    }

}

