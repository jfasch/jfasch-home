#include <vector>
#include <iostream>

class Matrix
{
public:
    Matrix(unsigned xdim, unsigned ydim)
    : _xdim(xdim), _ydim(ydim), _data(xdim*ydim) {}

    const int& at(unsigned x, unsigned y) const
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return _data.at(y*_ydim + x);                  // <-- duplicate code
    }
    int& at(unsigned x, unsigned y)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return _data.at(y*_ydim + x);                  // <-- duplicate code
    }

private:
    unsigned _xdim, _ydim;
    std::vector<int> _data;
};

int main()
{
    Matrix m(2,2);
    m.at(1,1) = 42;
    std::cout << m.at(1,1) << std::endl;               // <-- non-const at()
    const Matrix& cm = m;
    std::cout << cm.at(1,1) << std::endl;              // <-- const at()
    return 0;
}
