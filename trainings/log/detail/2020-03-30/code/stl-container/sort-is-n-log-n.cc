// the sort<> algorithm is said to be O(n*log(n)). see what that means
// in numbers: use sort<> with a comparison function that counts how
// often it is called.

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// "functor" class, defining the function call operator to have the
// signature that is required by sort<>.
class less_than_counting
{
public:
    less_than_counting(size_t& num) : _num(num) {}

    bool operator()(int l, int r) const { _num++; return l<r; }

private:
    size_t& _num;
};

int main()
{
    {
        vector<int> a{6,5,4,3,7,8,9,0,1};
    
        size_t num_comparisons = 0;

        less_than_counting lt(num_comparisons); // instantiate functor
        sort(a.begin(), a.end(), lt); // invoke sort with it (rather
                                      // than the built-in '<'
                                      // operator on int)

        for (auto elem: a)
            cout << elem << endl;

        cout << "#comparisons to sort " << a.size() << " elements: " << num_comparisons << endl;
    }

    {
        vector<int> a{6,5,4,3,7,8,9,0,1};
        size_t num_comparisons = 0;
        sort(a.begin(), a.end(),
             // exactly the same as the functor above, only written in
             // one line *at its usage* - rather than written in >10
             // lines scattered around the code.
             [&num_comparisons](int l, int r){num_comparisons++;return l<r;});
        cout << "#comparisons to sort " << a.size() << " elements: " << num_comparisons << endl;
    }

    return 0;
}
