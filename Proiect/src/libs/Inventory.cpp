#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include <algorithm>
#include <thread>
#include <semaphore.h>
#include <memory>
#include "Inventory.hpp"


Inventory::Inventory(std::vector<std::shared_ptr<Item>> items)  {
        this->items = items;
}

Inventory::~Inventory(){ 
}



void Inventory::addItemByReferrence(std::shared_ptr<Item> item) {

    std::lock_guard<std::mutex> lock(mutex);

    // Creating a shared pointer from the provided item by making a copy
    std::weak_ptr<Item> itemToAdd= item;

    items.push_back(itemToAdd.lock());
    
    // Add delay to simulate work
    //std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "In thread: " << std::this_thread::get_id() << " adding an item" << std::endl;

}

void Inventory::addItem(std::shared_ptr<Item> item){
        std::lock_guard<std::mutex> lock(mutex);
        items.push_back(item);
        //add delay to simulate work
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<<"In thread: " << std::this_thread::get_id() <<" adding an item"<< std::endl;
        mutex.unlock();

    }

void Inventory::removeItem(const char* itemName) {
    std::lock_guard<std::mutex> lock(mutex);
    std::weak_ptr<Item> itemToRemove;

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout<<"In thread: " << std::this_thread::get_id() <<" removing an item"<< std::endl;
    for (auto& item : items) { // Remove const qualifier from item
        if (strcmp(item->getItemName(), itemName) == 0) {
            itemToRemove = item;
            break; 
        }
    }

    if (itemToRemove.expired()) {
        std::cout << "Item not found." << std::endl;
    } else {
        auto sharedItemToRemove = itemToRemove.lock(); // Convert weak_ptr to shared_ptr
        auto it = std::find(items.begin(), items.end(), sharedItemToRemove);
        if (it != items.end()) {
            sharedItemToRemove.reset();
            items.erase(it);
            std::cout << "Item found and removed. " << sharedItemToRemove.use_count()<< std::endl;
        } else {
            std::cout << "Error: Item not found in the vector."<< sharedItemToRemove.use_count() << std::endl;
        }
    }
}


void Inventory::displayInventory() const {
        std::lock_guard<std::mutex> lock(mutex);
        for (const auto& sharedPtr : items) {
            if(sharedPtr) {
                sharedPtr->display();
            }
        }
    }


void Inventory::processItems(std::shared_ptr<Item> item1, std::shared_ptr<Item> item2) {
        std::weak_ptr<Item> observer = item2;
        
        std::cout << "Processing item 1...\n";
        std::cout<<item2.use_count();
        srand(time(NULL));
        int random = rand() % 100;
        std::cout << random << std::endl;
        
        if (random % 2 == 0) {
            item2.reset();
        }

        if (!observer.expired()) {
            std::cout << "Processing item 2...\n";
            item2.reset();
        } else {
            std::cout << "Item 2 already processed, leaving...\n";
        }
    }
