#include <map>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <memory>
#include <variant>

using namespace std::chrono_literals;

class TodoList final
{
public:
    TodoList() = default;
    TodoList(std::initializer_list<std::pair<std::string, std::function<void()>>> l)
    {
        for (const auto& [name, func]: l)
            _list[name] = func;
    }
    TodoList(const TodoList&) = delete;
    TodoList& operator=(const TodoList&) = delete;

    void add_item(const std::string& name, std::function<void()> func)
    {
        _list[name] = todo_item(func);
    }

    void start()
    {
        for (auto& [name, item]: _list)
            item = std::make_shared<std::thread>(std::get<0>(item));
    }
    void wait()
    {
        for (auto& [name, item]: _list)
            std::get<1>(item)->join();
    }

private:
    using todo_item = std::variant<std::function<void()>, std::shared_ptr<std::thread>>;
    using todo_list = std::map<std::string, todo_item>;

    todo_list _list;
};

int main()
{
    TodoList tdl{
        {"up 1 to 10",
         [](){
             for (int i=1; i<=10; i++) {
                 std::cout << "UP: " << i << std::endl;
                 std::this_thread::sleep_for(1s);
             }
         }
        },
        {"down 1000 to 980",
         [](){
             for (int i=1000; i>=980; i--) {
                 std::cout << "DOWN: " << i << std::endl;
                 std::this_thread::sleep_for(0.5s);
             }
         }
        }
    };
    
    tdl.start();
    tdl.wait();

    return 0;
}
