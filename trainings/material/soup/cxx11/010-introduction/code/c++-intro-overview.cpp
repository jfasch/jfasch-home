#include <map>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <memory>


using namespace std::chrono_literals;

int main()
{
    using todo_list_item = std::pair<std::function<void()>, std::shared_ptr<std::thread>>;
    using todo_list = std::map<std::string /*name*/, todo_list_item>;

    todo_list tdl{
        {"up",
         {
             [](){
                 for (int i=0; i<10; i++) {
                     std::cout << "up " << i << std::endl;
                     std::this_thread::sleep_for(1s);
                 }
             },
             nullptr
         },
        }, 
        {"down",
         {
             [](){
                 for (int i=1000; i>980; i--) {
                     std::cout << "down " << i << std::endl;
                     std::this_thread::sleep_for(0.5s);
                 }
             },
             nullptr
         },
        },
    };

    // start threads
    for (auto& [name, desc]: tdl) {
        std::cout << "START NAME: " << name << std::endl;
        auto& [func, threadptr] = desc;

        threadptr.reset(new std::thread(func));
    }

    // wait for threads
    for (auto& [name, desc]: tdl) {
        std::cout << "WAIT NAME: " << name << std::endl;
        auto& [func, threadptr] = desc;

        threadptr->join();
    }

    return 0;
}
