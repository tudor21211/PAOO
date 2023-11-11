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
        const char* compareSize(const Telefon& otherPhone);
        static void analyzePhones(Telefon *phones, int numPhones);
        Telefon operator=(Telefon a);

};