#include<iostream>
#include "Telefon.hpp"
//Pisica a (Pisica("Miau"))
//Pisica a (std::move(Pisica("Miau")))



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

//copy constructorul copiaza atributele intr-un nou obiect si le pune in memorie la o zona diferita
//move constructorul pointeaza catre atributele altui obiect la aceeasi zona de memorie

return 0;
}