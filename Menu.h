//
// Created by mauluna52 on 3/04/23.
//

#ifndef PROYECTO1_BATTLESPACE_MENU_H
#define PROYECTO1_BATTLESPACE_MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;
class Menu {
private:
    RenderWindow* window;
    RectangleShape* button1;
    RectangleShape* button2;
    RectangleShape* button3;
    void initWindow();

public:
    Menu();
    virtual ~Menu();

    void run();
    void update();
    void render();
};



#endif //PROYECTO1_BATTLESPACE_MENU_H
