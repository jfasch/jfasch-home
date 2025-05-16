#include <map>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <memory>
#include <variant>

using namespace std::chrono_literals;

int main()
{
    using todo_item = std::variant<std::function<void()>, std::shared_ptr<std::thread>>;
    using todo_list = std::map<std::string, todo_item>;

    todo_list tdl{
        { "up 1 to 10",
          [](){
              for (int i=1; i<=10; i++) {
                  std::cout << "UP: " << i << std::endl;
                  std::this_thread::sleep_for(1s);
              }
          },
        },
        { "down 1000 to 980",
          [](){
              for (int i=1000; i>=980; i--) {
                  std::cout << "DOWN: " << i << std::endl;
                  std::this_thread::sleep_for(0.5s);
              }
          },
        },
    };

    for (auto& [name, item]: tdl) {
        std::cout << "---------------- Starting NAME: " << name << std::endl;
        item = std::make_shared<std::thread>(std::get<0>(item));
    }

    for (auto& [name, item]: tdl) {
        std::cout << "---------------- Starting NAME: " << name << std::endl;
        std::get<1>(item)->join();
    }

    return 0;
}
