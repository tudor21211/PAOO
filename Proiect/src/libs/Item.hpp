#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include <string>
#include <memory>
#include <thread>

class Item{

public:

    Item(const char* name, int quantity);
    ~Item();

    void setQuantity(int quantity);
    void setName(const char* name);
    void display() const;
    void incrementQuantity();
    int getQuantity() const;
    const char* getItemName() const;

private: 
    char * name;  
    int quantity;
    sem_t quantitySemaphore;
};
#endif