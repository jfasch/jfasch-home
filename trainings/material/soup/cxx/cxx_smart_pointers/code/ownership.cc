#include "data.h"

#include <gtest/gtest.h>

#include <string>
#include <iostream>
#include <memory>

using namespace std;


class FuzzyDataOwner
{
public:
    FuzzyDataOwner(Data* data) : _data(data) {}
    ~FuzzyDataOwner() { delete _data; }
    const Data& data() const { return *_data; }
private:
    Data* _data;
};

class SharedDataOwner
{
public:
    SharedDataOwner(std::shared_ptr<Data> data) : _data(data) {}
    const Data& data() const { return *_data; }
private:
    std::shared_ptr<Data> _data;
};

class UniqueDataOwner
{
public:
    UniqueDataOwner(std::unique_ptr<Data>&& data) : _data(std::move(data)) {}
    const Data& data() const { return *_data; }
private:
    std::unique_ptr<Data> _data;
};

TEST(Ownership, FuzzyOwnership)
{
    Data* data = new Data(new char[28], 28);
    FuzzyDataOwner owner(data);

    // must know that data is now owned by somebody else. MUST NOT
    // DELETE!
}

TEST(Ownership, SharedOwnership_Bad)
{
    Data* data = new Data(new char[28], 28);
    (void)data;
    {
        SharedDataOwner owner(std::shared_ptr<Data>(data));
        // owner dtor called here!
    }

    // explicitly transferred ownership into shared_ptr. MUST NOT
    // ACCESS once owner dtor has been called.
}

TEST(Ownership, SharedOwnership_Good)
{
    std::shared_ptr<Data> data(new Data(new char[28], 28));
    {
        SharedDataOwner owner(data);
        // owner dtor called here!
    }

    // safely access data (which is what shared ownership is all
    // about)
    std::string s = data->data();
}

TEST(Ownership, UniqueOwnership)
{
    std::unique_ptr<Data> data(new Data(new char[28], 28));
    UniqueDataOwner owner(std::move(data));

    ASSERT_EQ(data.get(), nullptr);
}

