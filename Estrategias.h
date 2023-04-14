#include <iostream>
#include <map>
#include <tinyxml2.h>
#include <sstream>

#ifndef PROYECTO1_BATTLESPACE_ESTRATEGIAS_H
#define PROYECTO1_BATTLESPACE_ESTRATEGIAS_H

using namespace std;
using namespace tinyxml2;

class Power {
public:
    string name;
    string description;
    int time;
    float cost;

    //para paged powers
    Power();
    virtual ~Power();
    void asignarArchivo1(int valor);
    void asignarArchivo2(float valor);


   /* static Power ReadFromXml(const char* filename) {
        Power power;
        XMLDocument doc;
        doc.LoadFile(filename);

        XMLElement* power_element = doc.FirstChildElement("Estrategias")->FirstChildElement("Power");
        if (power_element) {
            XMLElement* name_element = power_element->FirstChildElement("name");
            if (name_element) {
                power.name = name_element->GetText();
            }
            XMLElement* description_element = power_element->FirstChildElement("description");
            if (description_element) {
                power.description = description_element->GetText();
            }
            XMLElement* time_element = power_element->FirstChildElement("time");
            if (time_element) {
                std::istringstream iss(time_element->GetText());
                iss >> power.time;
            }
            XMLElement* cost_element = power_element->FirstChildElement("cost");
            if (cost_element) {
                std::istringstream iss(cost_element->GetText());
                iss >> power.cost;
            }
        }

        return power;
    }*/
private:
    //para paged powers
    int* valor1;
    float* valor2;
};

class Estrategias {
public:
    int prueba();
    Power* available_powers[2];

};


#endif //PROYECTO1_BATTLESPACE_ESTRATEGIAS_H