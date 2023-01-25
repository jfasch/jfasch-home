#include <vector>

class Object
{
public:
    Object(int id) : _id(id) {}
    int id() const { return _id; }
private:
    int _id;
};

class ObjectContainer
{
public:
    void add_object(Object* o) { _container.push_back(o); }
    
private:
    using _Container = std::vector<Object*>;
    _Container _container;
};

int main()
{
    ObjectContainer container;
    Object* o = new Object(666);
    container.add_object(o);

    return 0;
}
