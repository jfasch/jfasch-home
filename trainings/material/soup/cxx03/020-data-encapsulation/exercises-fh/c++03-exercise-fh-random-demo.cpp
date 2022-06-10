#include <random>
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 3) {
        std::cerr << argv[0] << ": <low> <high>" << std::endl;
        return 1;
    }

    double low = std::stod(argv[1]);
    double high = std::stod(argv[2]);

    std::uniform_real_distribution<double> distribution(low, high);  // <--- HERE
    std::default_random_engine engine{std::random_device{}()};       // <--- HERE

    while (true) {
        double number = distribution(engine);                        // <--- HERE
        std::cout << number << std::endl;
    }

    return 0;
}
