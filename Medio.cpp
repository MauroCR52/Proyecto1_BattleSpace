#include "Medio.h"
#include "iostream"

Medio::Medio() {
    this->initWindow();
}

Medio::~Medio() {
    delete this->window;
}

void Medio::run() {
    while (this->window->isOpen()){
        this->update();
        this->render();
    }
}

void Medio::update() {
    Event e;
    while (this->window->pollEvent(e)) {
        if(e.Event::type == Event::Closed)
            this->window->close();
        if (e.Event::key.code == Keyboard::Escape)
            this->window->close();

    }
}

void Medio::render() {
    this->window->clear(Color(137, 155, 176, 255));
    //Enseña la ventana
    this->window->display();

}

void Medio::initWindow() {
    this->window = new RenderWindow(VideoMode(800, 600), "Medio - Battlespace", Style::Titlebar | Style::Close);
}
