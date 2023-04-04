#include "iostream"
#include "Menu.h"
#include "Facil.h"

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
            this->button1->setFillColor(Color::Blue);
            this->window->close();
            Facil facil;
            facil.run();
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

    //Enseña la ventana
    this->window->display();

}

void Menu::initWindow() {
    this->font.loadFromFile("/home/mauluna52/CLionProjects/Proyecto1_BattleSpace/fonts/ChakraPetch-Regular.ttf");
    this->window = new RenderWindow(VideoMode(800, 600), "Menu - Battlespace", Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(144);

    this->window->setVerticalSyncEnabled(false);
    this->button1 = new RectangleShape(Vector2f(100, 50));
    this->button2 = new RectangleShape(Vector2f(100, 50));
    this->button3 = new RectangleShape(Vector2f(100, 50));
    this->buttonText = new Text("Facil", this->font, 20);
    this->buttonText2 = new Text("Medio", this->font, 20);
    this->buttonText3 = new Text("Dificil", this->font, 20);

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