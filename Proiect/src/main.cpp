#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>

#include "Device.hpp"
#include "AndroidDevice.hpp"


using namespace device;
int main () {

    Smartphone smartphone1 = Smartphone("Smartphone1", "Black", 5.5, "Samsung", "Galaxy S10");

   
    //smartphone1 = std::move(Smartphone("Smartphone2", "White", 6.5, "Hwawei", "Halo 2"));

  
    smartphone1.getAllInfo();
    
   Smartphone *myPhone = new AndroidDevice("Smartphone3", "Black", 5.5, "Samsung", "Galaxy S10", "Android 10");

   myPhone->getAllInfo();

   
   


 



}