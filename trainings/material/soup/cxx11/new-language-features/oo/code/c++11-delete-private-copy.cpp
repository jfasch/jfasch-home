class OwnsMemory
{
public:
    OwnsMemory(unsigned amount) : _mem{new char[amount]} {}
    ~OwnsMemory() { delete[] _mem; }

private:
    char* _mem;

    OwnsMemory(const OwnsMemory&);
    void operator=(const OwnsMemory&);
};

int main()
{
    OwnsMemory om(100);
    OwnsMemory om_copy = om;
    return 0;
}
