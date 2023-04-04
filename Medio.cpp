#include "iostream"
#include "Medio.h"
void Medio::initWindow() {
    this->window = new RenderWindow(VideoMode(800, 600), "Medio - Battlespace", Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

Medio::Medio() {
    this->initWindow();
    this->initPlayer();
}

Medio::~Medio() {
    delete this->window;
    delete this->player;
}

void Medio::run() {
    while (this->window->isOpen()){
        this->update();
        this->render();
    }
}

void Medio::update() {
    this->updatePollEvents();
    this->updateInput();
}

void Medio::render() {
    this->window->clear(Color(137, 155, 176, 255));
    //Enseña la ventana
    this->player->render(*this->window);
    this->window->display();

}


void Medio::initPlayer() {
    this->player = new Player();
}

void Medio::updatePollEvents() {
    Event e;
    while (this->window->pollEvent(e)) {
        if(e.Event::type == Event::Closed)
            this->window->close();
        if (e.Event::key.code == Keyboard::Escape)
            this->window->close();
    }
}

void Medio::updateInput() {
    if(Keyboard::isKeyPressed(Keyboard::Up))
        this->player->move(-1.f);
    if(Keyboard::isKeyPressed(Keyboard::Down))
        this->player->move(1.f);
}
