#include "Smartphone.hpp"
#include <iostream>
#include <string.h> 
#include <stdio.h>


class AndroidDevice : public Smartphone {

    protected:
    char *androidVersion;

    public:

    AndroidDevice(const char *name, const char *color, float size, const char *brand, const char *model, const char *androidVersion);
    ~AndroidDevice();
    char* getAndroidVersion() const;
    
    void getAllInfo() const override;


};

