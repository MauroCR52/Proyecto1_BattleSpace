#include "iostream"
#include "Facil.h"

void Facil::initWindow() {
    this->window = new RenderWindow(VideoMode(800, 600), "Facil - Battlespace", Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

Facil::Facil() {
    this->initWindow();
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
    Event e;
    while (this->window->pollEvent(e)) {
        if(e.Event::type == Event::Closed)
            this->window->close();
        if (e.Event::key.code == Keyboard::Escape)
            this->window->close();

    }
    // Mover el jugador
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

