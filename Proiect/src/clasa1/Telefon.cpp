#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
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