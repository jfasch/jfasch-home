#include <mutex>
#include <iostream>

std::mutex lock;
int shared_count = 0;
const char* shared_resource;

void shared_resource_alloc()
{
    shared_resource = new const char[]{"Howdy"};
}
void shared_resource_free()
{
    delete[] shared_resource;
}

int main()
{
    if (std::scoped_lock _(lock); shared_count == 0) {
        shared_resource_alloc();
        ++shared_count;
    }

    std::cout << shared_resource << '\n';

    if (std::scoped_lock _(lock); shared_count == 1)
        shared_resource_free();

    return 0;
}
