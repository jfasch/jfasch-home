#include <vector>
#include <iostream>

class Matrix
{
public:
    Matrix(unsigned xdim, unsigned ydim)
    : _xdim(xdim), _ydim(ydim), _data(xdim*ydim) {}

    template <typename Self>
    auto& at(this Self& self, unsigned x, unsigned y)
    {
        return self._data.at(y*self._ydim + x);
    }

private:
    unsigned _xdim, _ydim;
    std::vector<int> _data;
};

int main()
{
    Matrix m(2,2);
    m.at(1,1) = 42;
    std::cout << m.at(1,1) << std::endl;
    const Matrix& cm = m;
    std::cout << cm.at(1,1) << std::endl;
    return 0;
}
