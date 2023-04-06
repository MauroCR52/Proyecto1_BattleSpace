#include "iostream"
#include "Estrategias.h"

int Estrategias::prueba() {

    ptree pt1, pt2, pt3, pt4;

    read_xml("/home/mauluna52/CLionProjects/Proyecto1_BattleSpace/Estrategia1.xml", pt1);
    read_xml("/home/mauluna52/CLionProjects/Proyecto1_BattleSpace/Estrategia2.xml", pt2);
    read_xml("/home/mauluna52/CLionProjects/Proyecto1_BattleSpace/Estrategia3.xml", pt3);
    read_xml("/home/mauluna52/CLionProjects/Proyecto1_BattleSpace/Estrategia4.xml", pt4);

    int numero1 = pt1.get<int>("estrategia.numero");
    auto nombre1 = pt1.get<string>("estrategia.poder.nombre");
    auto descripcion1 = pt1.get<string>("estrategia.poder.descripcion");

    int numero2 = pt2.get<int>("estrategia.numero");
    auto nombre2 = pt2.get<string>("estrategia.poder.nombre");
    auto descripcion2 = pt2.get<string>("estrategia.poder.descripcion");

    int numero3 = pt3.get<int>("estrategia.numero");
    auto nombre3 = pt3.get<string>("estrategia.poder.nombre");
    auto descripcion3 = pt3.get<string>("estrategia.poder.descripcion");

    int numero4 = pt4.get<int>("estrategia.numero");
    auto nombre4 = pt4.get<string>("estrategia.poder.nombre");
    auto descripcion4 = pt4.get<string>("estrategia.poder.descripcion");

   /* cout << "Estrategia 1: " << numero1 << endl;
    cout << "Nombre: " << nombre1 << endl;
    cout << "Descripcion: " << descripcion1 << endl;

    cout << "Estrategia 2: " << numero2 << endl;
    cout << "Nombre: " << nombre2 << endl;
    cout << "Descripcion: " << descripcion2 << endl;

    cout << "Estrategia 3: " << numero3 << endl;
    cout << "Nombre: " << nombre3 << endl;
    cout << "Descripcion: " << descripcion3 << endl;

    cout << "Estrategia 4: " << numero4 << endl;
    cout << "Nombre: " << nombre4 << endl;
    cout << "Descripcion: " << descripcion4 << endl;*/

    return 0;

}