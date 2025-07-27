#include <thread>
#include <iostream>

int main()
{
    std::thread t([](){
        std::cout << "Hello Thread" << std::endl;
    });
    t.join();
    std::cout << "Bye" << std::endl;
    return 0;
}
