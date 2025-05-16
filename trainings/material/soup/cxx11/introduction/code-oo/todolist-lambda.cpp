#include <map>
#include <string>
#include <functional>
#include <iostream>

int main()
{
    using todo_list = std::map<std::string, std::function<void()>;

    const todo_list tdl = {
        { "up 1 to 10",
          [prefix="blah"](){                                                 // <-- functor with one member 'prefix'
              for (int i=1; i<=10; i++)
                  std::cout << _prefix << ", UP: " << i << '\n';
          }
        },
        { "down 1000 to 980",
          [](){                                                              // <-- functo without a member
              for (int i=1000; i>=980; i--)
                  std::cout << "DOWN: " << i << '\n';
          }
        },
    };

    for (const auto& [name, item]: tdl) {
        std::cout << "NAME: " << name << ", ";
        item();                                                              // <-- "behaves-like-a" function
        std::cout << '\n';
    }

    return 0;
}
