#include<iostream>
#include "Telefon.hpp"


int main() {

const char *nume = "OnePlus";
const char *color = "Green";
float size = 8.23;

Telefon t1 = Telefon(nume,color,size); //apelat class constructor

std::cout<<"t1 color is:"<<t1.getColor()<<"\n";

Telefon t2(t1); // apelat copy constructor

std::cout<<"t2 color is:"<<t2.getColor()<<"\n";



Telefon t3(std::move(t1)); //apelat move constructor
std::cout<<"t3 color is:"<<t3.getColor()<<"\n";

t1.setColor("Blue");

std::cout<<"t3 color after setting t1 to blue:"<<t3.getColor()<<"\n";

std::cout<<"t1 color address is "<<static_cast<const void*>(t1.getColor())<<"\n"<<"t2 color address is "<<static_cast<const void*>(t2.getColor())<<"\n"<<"t3 color address is "<<static_cast<const void*>(t3.getColor())<<"\n"; 


std::cout<<t2.compareSize(t1)<<"\n";


Telefon *phones = new Telefon[3]{
        Telefon("Phone1", "Red", 5.5),
        Telefon("Phone2", "Black", 6.0),
        Telefon("Phone3", "Red", 5.8)
    };


Telefon::analyzePhones(phones, 3);


delete[] phones;


return 0;
}