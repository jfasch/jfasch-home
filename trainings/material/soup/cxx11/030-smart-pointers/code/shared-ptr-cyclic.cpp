#include "sensors.h"

#include <gtest/gtest.h>
#include <memory>

class NonSense
{
public:
    void set_reference(std::shared_ptr<NonSense> ref)
    {
        _ref = ref;
    }

private: 
    std::shared_ptr<NonSense> _ref;
};

TEST(shared_ptr_suite, cyclic_reference)
{
    std::shared_ptr<NonSense> cycle(new NonSense);
    cycle->set_reference(cycle);
}
