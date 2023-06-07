#include <random>
#include <iostream>

int main()
{
    // setup how we want our random numbers to be created (think:
    // object initialization)
    double lo = 36.1;
    double hi = 42.7;

    // object state. think: what does the object need during runtime?
    std::random_device rd;                                       // <--- /dev/random, used to obtain a seed
    std::default_random_engine engine(rd());                     // <--- init (and seed) RNG
    std::uniform_real_distribution<double> distribution(lo, hi); // <--- tailor desired distribution

    // draw 10 random numbers (think: measure temperature)
    for (int i=0; i<10; i++) {
        double number = distribution(engine);                    // <--- use uniform_real_distribution to 
                                                                 //      draw a number from engine
                                                                 //      and bend it to desired range
                                                                 
        std::cout << number << std::endl;
    }

    return 0;
}
