#include <vector>
#include <iostream>

class IntMatrix
{
public:
    IntMatrix(unsigned xdim, unsigned ydim) : _xdim(xdim), _ydim(ydim), _data(xdim*ydim) {}
    const int& at(unsigned x, unsigned y) const
    {
        return at(*this, x, y);
    }
    int& at(unsigned x, unsigned y)
    {
        return at(*this, x, y);
    }

private:
    template <typename Self>
    static auto& at(/*this*/ Self& self, unsigned x, unsigned y)
    {
        return self._data.at(y*_ydim + x);
    }

private:
    unsigned _xdim, _ydim;
    std::vector<int> _data;
};

int main()
{
    IntMatrix m(2,2);
    m.at(1,1) = 42;
    std::cout << m.at(1,1) << std::endl;
    const IntMatrix& cm = m;
    std::cout << cm.at(1,1) << std::endl;
    return 0;
}
