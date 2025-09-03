#include <map>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

void up_1_to_10()
{
    for (int i=1; i<=10; i++) {
        std::cout << "UP: " << i << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

void down_1000_to_980()
{
    for (int i=1000; i>=980; i--) {
        std::cout << "DOWN: " << i << std::endl;
        std::this_thread::sleep_for(0.5s);
    }
}

int main()
{
    using todo_list = std::map<std::string, void(*)()>;

    todo_list tdl{
        { "up 1 to 10",         up_1_to_10 },
        { "down 1000 to 980",   down_1000_to_980},
    };

    for (const auto& [name, func]: tdl) {
        std::cout << "---------------- Running NAME: " << name << std::endl;
        func();
    }

    return 0;
}
