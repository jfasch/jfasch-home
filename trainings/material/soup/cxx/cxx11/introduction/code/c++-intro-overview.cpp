#include <map>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <variant>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char** argv)
{
    using todo_item = std::pair<std::function<void()>, std::shared_ptr<std::thread>>;
    using todo_list = std::map<std::string, todo_item>;

    todo_list tdl{
        { "up 1 to 10",
          {
              [](){
                  for (int i=1; i<=10; i++) {
                      std::cout << "UP: " << i << std::endl;
                      std::this_thread::sleep_for(1s);
                  }
              },
              nullptr
          }
        },
        { "down 1000 to 980",
          {
              [](){
                  for (int i=1000; i>=980; i--) {
                      std::cout << "DOWN: " << i << std::endl;
                      std::this_thread::sleep_for(0.5s);
                  }
              },
              nullptr
          }          
        },
    };

    if (argc == 2) {
        // add countdown
        tdl["COUNTDOWN"] = std::make_pair(
            [start=std::stoi(argv[1])](){
                int i = start;
                while (i) {
                    std::cout << "COUNTDOWN: " << i-- << std::endl;
                    std::this_thread::sleep_for(2s);
                }
            },
            nullptr
        );
    }

    for (auto& [name, item]: tdl) {
        std::cout << "---------------- Running NAME: " << name << std::endl;
        item.second = std::make_shared<std::thread>(std::get<0>(item));
    }

    for (auto& [name, item]: tdl) {
        std::cout << "---------------- Running NAME: " << name << std::endl;
        item.second->join();
    }

    return 0;
}
