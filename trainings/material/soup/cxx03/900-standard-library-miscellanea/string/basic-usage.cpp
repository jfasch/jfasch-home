#include <string>
#include <iostream>


int main()
{
    // ctor and addition
    {
        std::string hello("Hello");
        std::string another_hello = hello;
        std::string who = "Joerg";

        std::string greeting = hello;
        greeting += " ";
        greeting += who;

        std::cout << greeting << std::endl;
    }

    // comparison
    {
        std::string a = "abc";
        std::string b = "def";
        if (a < b)
            std::cout << "jojo, " << b << " ist groesser" << std::endl;
        else
            std::cout << "hmmm" << std::endl;
        std::string c = max(a,b);
        std::cout << c << std::endl;

        // these are also supported
        //a > b;
        //a <= b;
        //a >= b;

        std::string d = "Joerg";
        std::string e = "Joerg";

        if (d == e)
            std::cout << "gleich" << std::endl;
        else
            std::cout << "nix gleich" << std::endl;

#define max(a,b) ((a) < (b))? (b): (a)      // can define a macro
                                            // here, legally. this
                                            // does not means that I
                                            // have to.
    }
    
    return 0;
}
