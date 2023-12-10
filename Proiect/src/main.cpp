#include <iostream>
#include <thread>
#include <barrier>
#include "Item.cpp"
#include "Inventory.hpp"

std::barrier my_barrier{ 2 };

void my_waitBarrier() {
    my_barrier.arrive_and_wait();
}

int main() {

 
    const int numEmployees = 10;
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
    

    std::cout<<"Time taken: " << std::time(nullptr) - start <<" seconds"<< std::endl;
    warehouse.displayInventory();

    Item item("Item", 10);
    std::cout<<item.getQuantity()<<std::endl;

    std::thread t1([&]() -> void{
        std::this_thread::sleep_for(std::chrono::seconds(5));
        item.incrementQuantity();
        //in increment daca  nu adaugam semaforul, threadurile se vor suprapune 
        //si se vor afisa valori gresite deoarece nu se va face lock pe quantity
        
        //avand sleep 5 secunde daca foloseam doar mutex resursa era blocata deoarece
        //acest thread e in sleep 5 secunde
        //cu semafoare celelalte thread-uri pot executa in paralel deoarece semaforul are
        //initializat parametrul value cu valoarea 2 ceea ce inseamna ca 2 threaduri pot executa
        //in paralel
    });

    std::thread t2([&]() -> void{
        std::this_thread::sleep_for(std::chrono::seconds(2));
        item.incrementQuantity();
        my_waitBarrier();
        std::cout<<"t2 continued working..."<<std::endl;
    });

     std::thread t3([&]() -> void{
        item.incrementQuantity();
        my_waitBarrier();
         std::cout<<"t3 continued working..."<<std::endl;
    });
    
    t1.join();
    t2.join();
    t3.join();
    std::cout<<"Finished the threads with the lowest latency "<<std::endl;
    std::cout<<item.getQuantity()<<std::endl;
    


    warehouse.processItems(std::make_shared<Item>("A",1),std::make_shared<Item>("B",2));
    
    return 0;

}

