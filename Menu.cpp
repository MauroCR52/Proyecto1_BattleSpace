#include "iostream"
#include "Menu.h"
#include "Facil.h"
#include "Medio.h"
#include "Dificil.h"

using namespace std;
using namespace sf;

Menu::Menu() {
    this->initWindow();
}

Menu::~Menu() {
    delete this->window;
    delete this->button1;
    delete this->button2;
    delete this->button3;
    delete this->buttonText;
    delete this->buttonText2;
    delete this->buttonText3;
    delete this->TitleText;
    delete this->indicaciones;

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
        if (e.Event::type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left && this->button1->getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y)){
            this->window->close();
            Facil facil;
            facil.run();
        }
        if (e.Event::type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left && this->button2->getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y)){
            this->button2->setFillColor(Color::Blue);
            this->window->close();
            Medio medio;
            medio.run();
        }
        if (e.Event::type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left && this->button3->getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y)){
            this->button3->setFillColor(Color::Blue);
            this->window->close();
            Dificil dificil;
            dificil.run();
        }

    }
}

void Menu::render() {
    /*
    * Muestra la ventana renderizada
    */
    this->window->clear(Color(137, 155, 176, 255));
    this->window->draw(*this->button1);
    this->window->draw(*this->button2);
    this->window->draw(*this->button3);
    this->window->draw(*this->buttonText);
    this->window->draw(*this->buttonText2);
    this->window->draw(*this->buttonText3);
    this->window->draw(*this->TitleText);
    this->window->draw(*this->indicaciones);

    //Enseña la ventana
    this->window->display();

}

void Menu::initWindow() {
    this->font.loadFromFile("/home/fernandez/datos2/Proyecto1_BattleSpace/fonts/ChakraPetch-Regular.ttf");
    this->window = new RenderWindow(VideoMode(800, 600), "Menu - Battlespace", Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(144);

    this->window->setVerticalSyncEnabled(false);
    this->button1 = new RectangleShape(Vector2f(100, 50));
    this->button2 = new RectangleShape(Vector2f(100, 50));
    this->button3 = new RectangleShape(Vector2f(100, 50));
    this->buttonText = new Text("Facil", this->font, 20);
    this->buttonText2 = new Text("Medio", this->font, 20);
    this->buttonText3 = new Text("Dificil", this->font, 20);
    this->TitleText = new Text("BATTLESPACE", this->font, 40);
    this->indicaciones = new Text("Seleccione la dificultad", this->font, 30);

    TitleText->setPosition(Vector2f(270, 100));
    indicaciones->setPosition(Vector2f(245, 210));
    button1->setPosition(Vector2f(350, 275));
    button1->setFillColor(Color::Green);
    buttonText->setPosition(Vector2f(375, 290));

    button2->setPosition(Vector2f(350, 350));
    button2->setFillColor(Color::Green);
    buttonText2->setPosition(Vector2f(375, 360));

    button3->setPosition(Vector2f(350, 425));
    button3->setFillColor(Color::Green);
    buttonText3->setPosition(Vector2f(375, 435));

}