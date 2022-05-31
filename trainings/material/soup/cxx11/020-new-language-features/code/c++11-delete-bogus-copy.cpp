class OwnsMemory
{
public:
    OwnsMemory(unsigned amount) : _mem{new char[amount]} {}
    ~OwnsMemory() { delete[] _mem; }

private:
    char* _mem;
};

int main()
{
    OwnsMemory om(100);
    OwnsMemory om_copy = om;
    return 0;
}
