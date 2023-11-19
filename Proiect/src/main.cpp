#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>

#include "Device.hpp"
#include "AndroidDevice.hpp"


using namespace device;



int main () {


    
   Smartphone smartphone1 = std::move(Smartphone("Smartphone1", "White", 6.5, "Hwawei", "Halo 2"));

  
   smartphone1.getAllInfo();


   Smartphone smartphone2 = std::move(smartphone1);


   smartphone2.getAllInfo();
   smartphone1.getAllInfo();
    
   Smartphone *myPhone = new AndroidDevice("Smartphone3", "Black", 5.5, "Samsung", "Galaxy S10", "Android 10");

   myPhone->getAllInfo();


   //testing copy ellision 
   Smartphone smartphone3(Smartphone("Smartphone1", "White", 6.5, "Hwawei", "Halo 2"));
   //copy elission is used here to avoid copying the object
   smartphone3.getAllInfo();

   smartphone3.setColor("Red");
   smartphone2 = std::move(smartphone3);
   smartphone2.getAllInfo();

   smartphone2.getClassType();
   std::cout<<smartphone2.getSize()<<std::endl;


}