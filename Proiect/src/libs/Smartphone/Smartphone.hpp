#include <stdio.h>
#include "Device.hpp"

using namespace device;
class Smartphone : public Device {
    
    protected: 

        char *name;
        char *color;
        float size;
        char *brand;
        char *model;

    public:
        Smartphone();
        Smartphone(const char *name, const char *color, float size, const char *brand, const char *model);
        Smartphone(const Smartphone &smartphone);
        Smartphone(Smartphone &&smartphone);
        ~Smartphone();

        Smartphone& operator=(Smartphone &smartphone);
        Smartphone& operator=(Smartphone &&smartphone);
        
        char* getColor() const override;
        char* returnName() const override;
        void setColor(const char *newColor) override;
        float getSize() const override;
        void setSize(float newSize) override;
        void getClassType() const override;
        void setName(const char *newName);
        void getAllInfo() const override;


};
