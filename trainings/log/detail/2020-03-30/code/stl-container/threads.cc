#include <thread>
#include <iostream>


static void consume_cpu(size_t num)
{
    while (--num);
}

int main()
{
    size_t num_iterations_1 = 1000000;
    size_t num_iterations_2 = 100000000;
    size_t num_iterations_3 = 666;

    std::thread t1([&num_iterations_1](){while (--num_iterations_1);});
    std::thread t2([](size_t num){while (--num);}, num_iterations_2);
    std::thread t3(consume_cpu, num_iterations_3);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "num_iterations_1: " << num_iterations_1 << std::endl;
    std::cout << "num_iterations_2: " << num_iterations_2 << std::endl;
    std::cout << "num_iterations_3: " << num_iterations_3 << std::endl;

    return 0;
}
