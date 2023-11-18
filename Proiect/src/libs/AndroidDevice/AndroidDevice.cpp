#include "AndroidDevice.hpp"
#include <iostream>
#include <stdio.h> 
#include <string.h>



AndroidDevice::AndroidDevice(const char *name, const char *color, float size, const char *brand, const char *model, const char *androidVersion) : Smartphone(name, color, size, brand, model) {
    this->androidVersion = new char[strlen(androidVersion) + 1];
    strcpy(this->androidVersion, androidVersion);
}


AndroidDevice::~AndroidDevice() {
    std::cout<<"Deleted an AndroidDevice"<<std::endl;
    delete[] this->androidVersion;
}


char* AndroidDevice::getAndroidVersion() const {
    return this->androidVersion;
}

void AndroidDevice::getAllInfo() const {
    std::cout<<"Android"<<" "<< this->name<<" "<< this->brand << " " <<this->color << " " << this->model<<std::endl;
}
