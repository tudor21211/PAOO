#ifndef DEVICE_HPP
#define DEVICE_HPP
#include <stdio.h>
#include <iostream>
#include <string.h>


namespace device {

    class Device {

        public:

            virtual char* getColor() const = 0;
            virtual char* returnName() const =0;
            virtual void getClassType() const =0;
            virtual float getSize() const=0;
            virtual void setColor(const char *newColor) =0;
            virtual void setSize(float newSize) =0;
            virtual void getAllInfo() const =0; 
            
    };

}


#endif