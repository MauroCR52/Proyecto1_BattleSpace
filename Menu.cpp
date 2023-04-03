//
// Created by mauluna52 on 3/04/23.
//
#include "iostream"
#include "Menu.h"

using namespace std;
using namespace sf;

Menu::Menu() {
    this->initWindow();
}

Menu::~Menu() {
    delete this->window;
    delete this->button1;
}


void Menu::run() {
    while (this->window->isOpen()){
        this->update();
        this->render();
    }
}

void Menu::update() {
    Event e;
    while (this->window->pollEvent(e)) {
        if(e.Event::type == Event::Closed)
            this->window->close();
        if (e.Event::key.code == Keyboard::Escape)
            this->window->close();
        if (e.Event::type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left && this->button1->getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
            this->button1->setFillColor(Color::Blue);
        else{
            this->button1->setFillColor(Color::Green);
        }
    }
}

void Menu::render() {
    /*
    * Muestra la ventana renderizada
    */
    this->window->clear(Color(255, 0, 0, 255));
    this->window->draw(*this->button1);

    //Enseña la ventana

    this->window->display();

}

void Menu::initWindow() {
    this->window = new RenderWindow(VideoMode(800, 600), "Menu - Battlespace", Style::Titlebar | Style::Close);
    this->button1 = new RectangleShape(Vector2f(100, 50));
    button1->setPosition(Vector2f(350, 275));
    button1->setFillColor(Color::Green);
}


