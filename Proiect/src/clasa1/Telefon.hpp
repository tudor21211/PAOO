#include <stdio.h>

class Telefon {

    private: 
        char *name;
        char *color;
        float size;

    public:

        Telefon(const char *name,const char *color, float size);
        
        Telefon(Telefon &t);

        Telefon(Telefon &&t);

        ~Telefon();

        char* getColor();

        char* returnName();

        float getSize();

        void setColor(const char *newColor);

};