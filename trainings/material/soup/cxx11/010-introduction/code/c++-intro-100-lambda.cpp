#include <map>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

using namespace std::chrono_literals;

int main()
{
    using todo_list = std::map<std::string, std::function<void()>>;

    todo_list tdl{
        { "up 1 to 10",
          [](){             // <---
              for (int i=1; i<=10; i++) {
                  std::cout << "UP: " << i << std::endl;
                  std::this_thread::sleep_for(1s);
              }
          }            
        },
        { "down 1000 to 980",
          [](){             // <---
              for (int i=1000; i>=980; i--) {
                  std::cout << "DOWN: " << i << std::endl;
                  std::this_thread::sleep_for(0.5s);
              }
          }            
        },
    };

    for (const auto& [name, func]: tdl) {
        std::cout << "---------------- Running NAME: " << name << std::endl;
        func();
    }

    return 0;
}
