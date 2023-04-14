#include "iostream"
#include "Estrategias.h"

int Estrategias::prueba() {

};

Power::Power(){ //constructor para paged powers
    valor1 = new int;
    valor2 = new float;
}

Power::~Power(){ //destructor para paged powerd
    delete valor1;
    delete valor2;
}

// Funciones de asignar y obtener los valores en espacios de memoria para paged powers
void Power::asignarArchivo1(int valor){
    *valor1 = valor;
}

void Power::asignarArchivo2(float valor){
    *valor2 = valor;
}

void ReadFromXml(const char* filename){
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
    //return power;
    int valor1 = 0;
    float valor2 = 0.0f;

    //return power;
    power.asignarArchivo1(valor1);
    power.asignarArchivo2(valor2);
}