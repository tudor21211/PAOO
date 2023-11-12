#ifndef DEVICE_INTERFACE_HPP
#define DEVICE_INTERFACE_HPP
#include <iostream>


class DeviceInterface {
    public : 
    virtual ~DeviceInterface() = default;
    virtual char* getColor() const = 0;
    virtual char* returnName() const =0;
    virtual float getSize() const=0;

    // Non-pure virtual function
    virtual void displayInfo() const {
        std::cout << "Device Information: ";
        std::cout << "Name: " << returnName() << ", Color: " << getColor() << ", Size: " << getSize() << std::endl;
    }

};

#endif