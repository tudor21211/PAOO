#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>

#include "Telefon.hpp"
#include "Device.hpp"

int main() {

const char *nume = "OnePlus";
const char *color = "Green";
float size = 8.23;

device::Device d1(nume,color,size); //apelat class constructor
device::Device d2(d1);
d1=d2;

Telefon t1(nume,color,size);
Telefon t2(t1);

t1.displayInfo();

return 0;
}