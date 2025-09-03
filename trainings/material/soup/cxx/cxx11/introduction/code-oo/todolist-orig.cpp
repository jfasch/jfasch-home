#include <map>
#include <string>
#include <iostream>

int main()
{
    using todo_list = std::map<std::string, std::string>;

    todo_list tdl;
    tdl["up 1 to 10"] = "prefix: 'UP', count up from 1 to 10, interval 1 second";
    tdl["down 1000 to 980"] = "prefix: 'DOWN', count down from 1000 to 980, interval 0.5 second";

    for (todo_list::const_iterator it=tdl.begin(); it!= tdl.end(); ++it) {
        std::string name = it->first;
        std::string desc = it->second;

        std::cout << "NAME: " << name << ", DESC: " << desc << std::endl;
    }

    return 0;
}
