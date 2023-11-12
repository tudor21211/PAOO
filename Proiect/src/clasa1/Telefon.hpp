#include <stdio.h>
#include "Device.hpp"
class Telefon : public device::Device{

    protected: 
        char *name;
        char *color;
        float size;

    public:
    
        Telefon(const char *name,const char *color, float size);
        Telefon(Telefon &t);
        Telefon(Telefon &&t);
        ~Telefon();


        void displayInfo() const override;
        
        const char* compareSize(const Telefon& otherPhone);
        static void analyzePhones(Telefon *phones, int numPhones);

};