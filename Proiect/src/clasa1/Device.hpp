#ifndef DEVICE_HPP
#define DEVICE_HPP
//Include guards are preprocessor directives that prevent the contents of a header file from being included more than once. 
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "DeviceInterface.hpp"

namespace device{

    class Device : public DeviceInterface {

    public: 
        char *name;
        char *color;
        float size;

    public:
        Device();
        Device(const char *name,const char *color, float size);
        Device(Device &t);
        Device(Device &&t);
        ~Device();
        Device &operator=(Device &other);


        char* getColor() const override;
        char* returnName() const override;
        float getSize() const override;


        void setColor(const char *newColor);
        const char* compareSize(Device& otherDevice);
    
    };
}

#endif