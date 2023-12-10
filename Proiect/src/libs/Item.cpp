#include <iostream>
#include <memory>
#include <string.h>
#include "Item.hpp"


Item::Item(const char* name, int quantity) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->quantity = quantity;
    sem_init(&this->quantitySemaphore, 0, 2);
}

Item::~Item(){
    delete[] name;
    sem_destroy(&quantitySemaphore);
}

void Item::display() const {
    std::cout << "Item: " << this->name << ", Quantity: " << this->quantity << std::endl;
}

void Item::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Item::setName(const char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

int Item::getQuantity() const {
    return this->quantity;
}

void Item::incrementQuantity() {
    sem_wait(&quantitySemaphore);
    for (int i = 0; i < 100000; ++i) {
    this->quantity++;
    }
    std::cout<<"Thread "<<std::this_thread::get_id()<<" finished its work"<<std::endl;
    sem_post(&quantitySemaphore);  
}

const char* Item::getItemName() const {
    return this->name;
}