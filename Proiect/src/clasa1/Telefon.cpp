#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
#include <unordered_set>
#include "Telefon.hpp"

using namespace std;

Telefon::Telefon (const char *name,const char *color, float size) {
    this->name = new char[strlen(name)+1];
    strcpy(this->name,name);
    this->color = new char[strlen(color)+1];
    strcpy(this->color,color);
    this->size = size;
    cout<<"Implemented class constructor \n";
}


Telefon::Telefon(Telefon &t) {
    this->name = new char[strlen(t.name)+1];
    strcpy(this->name,t.name);
    this->color = new char[strlen(t.color)+1];
    strcpy(this->color,t.color);
    this->size = t.size;
    cout<<"Implemented copy constructor \n";
}

Telefon::Telefon(Telefon &&t) {

    //cele 3 linii sunt doar pentru exemplificarea zonei spre care pointeaza
    //un obiect care e creat prin move
    this->name = t.name;
    this->color = t.color;
    this->size = t.size;

    cout<<"Implemented move constructor \n";
}

Telefon::~Telefon (){
    delete[] name, color;
    cout<<"Destructor called \n";
}

char* Telefon::getColor () {
    return this->color;
}

float Telefon::getSize () {
    return this->size;
}

void Telefon::setColor(const char *newColor){
    delete[] color;

    color = new char[strlen(newColor)+1];
    strcpy(this->color,newColor);

}

const char* Telefon::compareSize(const Telefon& otherPhone) {
    if (size > otherPhone.size) {
        return "Telefonul curent este mai mare in dimensiune decat telefonul dat";
    } else if (size < otherPhone.size) {
        return "Telefonul curent este mai mic in dimensiune decat telefonul dat.";
    } else {
        return "Telefonul curent are aceeasi dimensiune ca si telefonul dat.";
    }
}

void Telefon::analyzePhones(Telefon *phones, int numPhones) {
    float totalSize = 0.0;
    std::unordered_set<std::string> uniqueColors;

    for (int i = 0; i < numPhones; ++i) {
        totalSize += phones[i].size;
        uniqueColors.insert(phones[i].color);
    }

    float averageSize = totalSize / numPhones;

    std::cout << "The average size of the given phones is: " << averageSize << " and the number of unique colors is: " << uniqueColors.size() << "\n";
}