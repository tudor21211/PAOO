#include <iostream>
#include <string.h>
#include <vector>
#include <mutex>
#include <algorithm>
#include <thread>
#include <semaphore.h>
#include <memory>
#include <barrier>
#include "Item.hpp"

class Inventory
{ 
public:

    Inventory(std::vector<std::shared_ptr<Item>> items);
    ~Inventory();


    void addItem(std::shared_ptr<Item> item);
    void addItemByReferrence(std::shared_ptr<Item> item);
    void removeItem(const char* itemName);
    void processItems(std::shared_ptr<Item> item1, std::shared_ptr<Item> item2);
    void displayInventory() const;
 
private:
    std::vector<std::shared_ptr<Item>> items;
    mutable std::mutex mutex;
    int numThreads;

    sem_t addSemaphore;
    sem_t removeSemaphore;



};