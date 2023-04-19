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

    //archivos xml con sus punteros
    string ArchivoXml1 = "Estrategia1.xml";
    string ArchivoXml2 = "Estrategia2.xml";
    string ArchivoXml3 = "Estrategia3.xml";
    string ArchivoXml4 = "Estrategia4.xml";

    string* ArchivoXml1Ptr = &ArchivoXml1;
    string* ArchivoXml2Ptr = &ArchivoXml2;
    string* ArchivoXml3Ptr = &ArchivoXml3;
    string* ArchivoXml4Ptr = &ArchivoXml4;

    static Power ReadFromXml(const char*) {
        Power power;
        XMLDocument doc;
        doc.LoadFile("Estrategia1.xml");
        doc.LoadFile("Estrategia2.xml");
        doc.LoadFile("Estrategia3.xml");
        doc.LoadFile("Estrategia4.xml");

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
    }
};

class Estrategias {
public:
    int prueba();
    Power* available_powers[2];

};

#endif //PROYECTO1_BATTLESPACE_ESTRATEGIAS_H