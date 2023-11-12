#include "Device.hpp"
#include <string.h>
#include <iostream>

using namespace device;

Device::Device (const char *name,const char *color, float size) {
    this->name = new char[strlen(name)+1];
    strcpy(this->name,name);
    this->color = new char[strlen(color)+1];
    strcpy(this->color,color);
    this->size = size;
    std::cout<<"Implemented class constructor \n";
}


Device::Device(Device &t) {
    this->name = new char[strlen(t.name)+1];
    strcpy(this->name,t.name);
    this->color = new char[strlen(t.color)+1];
    strcpy(this->color,t.color);
    this->size = t.size;
    std::cout<<"Implemented copy constructor \n";
}

Device::Device(Device &&t) {

    //cele 3 linii sunt doar pentru exemplificarea zonei spre care pointeaza
    //un obiect care e creat prin move
    this->name = t.name;
    this->color = t.color;
    this->size = t.size;

    std::cout<<"Implemented move constructor \n";
}

Device::~Device (){
    delete[] name, color;
    std::cout<<"Destructor called \n";
}

char* Device::getColor () const {
    return this->color;
}

char* Device::returnName () const {
    return this->name;
}

float Device::getSize () const {
    return this->size;
}

Device& Device::operator=(Device &otherDevice){
    std::cout<<"OPERATOR = OVERLOAD \n";
    if (this != &otherDevice) {
        delete[] name;
        delete[] color;
        
        name = new char[strlen(otherDevice.name)+1];
        strcpy(name,otherDevice.name);
        color = new char[strlen(otherDevice.color)+1];
        strcpy(color,otherDevice.color);

        size = otherDevice.size;
    }
    return *this;

}



void Device::setColor(const char *newColor){
    delete[] color;

    color = new char[strlen(newColor)+1];
    strcpy(this->color,newColor);

}




