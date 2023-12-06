#include <iostream>
#include <thread>
#include "Item.cpp"
#include "Inventory.hpp"



int main() {
    /*const int numEmployees = 3;
    Inventory warehouse{std::vector<std::shared_ptr<Item>>()};


    auto addFunction = [&](const std::shared_ptr<Item>& item) {
        warehouse.addItem(item);
    };

    auto removeFunction = [&](const char* itemName) {
        warehouse.removeItem(itemName);
    };

    std::vector<std::thread> threads;
    std::time_t start = std::time(nullptr);
    for (int i = 0; i < numEmployees; ++i) {
        threads.emplace_back(addFunction, std::make_shared<Item>("Item", 10));
    }

    threads.emplace_back(removeFunction, "Item");

    for (auto& thread : threads) {
        thread.join();
    }
    

    std::cout<<"Time taken: " << std::time(nullptr) - start << std::endl;
    warehouse.displayInventory();

    Item item{"Item", 10};
    std::cout<<item.getQuantity()<<std::endl;

    std::thread t1([&]() -> void{
        item.incrementQuantity();
        //in increment daca  nu adaugam semaforul, threadurile se vor suprapune 
        //si se vor afisa valori gresite deoarece nu se va face lock pe quantity
    });
    std::thread t2([&]() -> void{
        item.incrementQuantity();
    });
    
    t1.join();
    t2.join();
    std::cout<<item.getQuantity()<<std::endl;
    */
    
    std::shared_ptr<Item> item;
    {
        std::shared_ptr<Item> item1 = std::make_shared<Item>("Item", 10);
        item = item1;
        std::cout << item1->getQuantity() << std::endl;

    }

    std::cout<<item.use_count()<<std::endl;

    
    return 0;

}
