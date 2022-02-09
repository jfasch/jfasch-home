#include <iostream>
using namespace std;

#include <algorithm>
#include <vector>


void output_stern(int i)
{
    const std::string prefix = "***";
    cout << prefix << i << endl;
}

void output_bindestrich(int i)
{
    const std::string prefix = "---";
    cout << prefix << i << endl;
}

class output_with_prefix
{
public:
    output_with_prefix(const std::string& prefix) : _prefix(prefix) {}
    void operator()(int i) const { cout << _prefix << i << endl; }
private:
    const std::string _prefix;
};

int main()
{
    std::vector<int> array = { 34, 45, 1, 3, 2, 666 };

    std::vector<int>::const_iterator begin = array.begin();
    std::vector<int>::const_iterator end = array.end();

    std::for_each(begin, end, output_stern);
    std::for_each(begin, end, output_bindestrich);

    // same, using a traditional functor class
    output_with_prefix dashes("---");
    output_with_prefix stars("***");

    for_each(begin, end, dashes);
    for_each(begin, end, stars);

    return 0;
}
