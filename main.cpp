#include <iostream>
#include "Menu.h"
#include <time.h>
#include "Estrategias.h"
#include "Collector.h"

int main()
{
    Collector* reciclaje = new Collector();
    Bullet::setReciclaje(reciclaje);
    Estrategias estrategias;
    estrategias.prueba();
    srand(static_cast<unsigned int>(time(0)));
    Menu menu;
    menu.run();

    return 0;
}
