#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
#include <unordered_set>
#include "Smartphone.hpp"


using namespace device;

Smartphone::Smartphone(const char *name, const char *color, float size, const char *brand, const char *model) {
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);
    this->size = size;
}


Smartphone::Smartphone(const Smartphone &otherSmartphone) {

    std::cout<<"Copied a smartphone"<<std::endl;

    this->name = new char[strlen(otherSmartphone.name) + 1];
    strcpy(this->name, otherSmartphone.name);
    this->color = new char[strlen(otherSmartphone.color) + 1];
    strcpy(this->color, otherSmartphone.color);
    this->size = otherSmartphone.size;
    this->brand = new char[strlen(otherSmartphone.brand) + 1];
    strcpy(this->brand, otherSmartphone.brand);
    this->model = new char[strlen(otherSmartphone.model) + 1];
    strcpy(this->model, otherSmartphone.model);

}



Smartphone::Smartphone(Smartphone &&otherSmartphone){
    std::cout<<"Moved a smartphone"<<std::endl;
    this->name = otherSmartphone.name;
    this->color = otherSmartphone.color;
    this->size = otherSmartphone.size;
    this->brand = otherSmartphone.brand;
    this->model = otherSmartphone.model;
    otherSmartphone.brand = nullptr;
    otherSmartphone.model = nullptr;
    otherSmartphone.name = nullptr;
    otherSmartphone.color = nullptr;
    otherSmartphone.size = 0;
}


Smartphone::~Smartphone() {
    std::cout<<"Deleted a smartphone"<<std::endl;
    delete[] this->name;
    delete[] this->color;
    delete[] this->brand;
    delete[] this->model;
}

Smartphone& Smartphone::operator=(Smartphone &otherSmartphone){
    if (this != &otherSmartphone) {
        delete[] this->brand;
        delete[] this->model;
        delete[] this->name;
        delete[] this->color;
        this->name = new char[strlen(otherSmartphone.name) + 1];
        strcpy(this->name, otherSmartphone.name);
        this->color = new char[strlen(otherSmartphone.color) + 1];
        strcpy(this->color, otherSmartphone.color);
        this->size = otherSmartphone.size;
        this->brand = new char[strlen(otherSmartphone.brand) + 1];
        strcpy(this->brand, otherSmartphone.brand);
        this->model = new char[strlen(otherSmartphone.model) + 1];
        strcpy(this->model, otherSmartphone.model);
    }
    return *this;
}




Smartphone& Smartphone::operator=(Smartphone &&smartphone) {
    if (this != &smartphone) {
        this->brand = smartphone.brand;
        this->model = smartphone.model;
        this->name = smartphone.name;
        this->color = smartphone.color;
        this->size = smartphone.size;
        smartphone.name = nullptr;
        smartphone.color = nullptr;
        smartphone.size = 0;
        smartphone.brand = nullptr;
        smartphone.model = nullptr;
    }
    return *this;
    }



void Smartphone::setName(const char *newName) {
    delete[] this->name;
    this->name = new char[strlen(newName) + 1];
    strcpy(this->name, newName);
}

void Smartphone::setColor(const char *newColor) {
    delete[] this->color;
    this->color = new char[strlen(newColor) + 1];
    strcpy(this->color, newColor);
}

char *Smartphone::getColor() const {
    return this->color;
}

char *Smartphone::returnName() const {
    return this->name;
}

void Smartphone::setSize(float newSize) {
    this->size = newSize;
}

float Smartphone::getSize() const {
    return this->size;
}


void Smartphone::getClassType() const {
    std::cout<<"Smartphone"<<std::endl;
}

void Smartphone::getAllInfo() const {
    std::cout<<"Smartphone"<<" "<< this->name<<" "<< this->brand << " " <<this->color << " " << this->model<<std::endl;
}