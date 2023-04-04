#include "Dificil.h"
#include "iostream"

Dificil::Dificil() {
    this->initWindow();
}

Dificil::~Dificil() {
    delete this->window;
}

void Dificil::run() {
    while (this->window->isOpen()){
        this->update();
        this->render();
    }
}

void Dificil::update() {
    Event e;
    while (this->window->pollEvent(e)) {
        if(e.Event::type == Event::Closed)
            this->window->close();
        if (e.Event::key.code == Keyboard::Escape)
            this->window->close();

    }
}

void Dificil::render() {
    this->window->clear(Color(137, 155, 176, 255));
    //Enseña la ventana
    this->window->display();

}

void Dificil::initWindow() {
    this->window = new RenderWindow(VideoMode(800, 600), "Dificil - Battlespace", Style::Titlebar | Style::Close);
}
