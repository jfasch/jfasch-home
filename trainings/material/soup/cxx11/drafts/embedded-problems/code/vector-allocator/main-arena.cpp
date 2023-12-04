template <std::size_t Bytes, std::size_t Alignment>
class Arena
{
public:
    explicit Arena() noexcept : _ptr{data()} {}
    void* allocate(std::size_t bytes)
    {
        return std::exchange(_ptr, _ptr + bytes);
    }
    void deallocate(void* ptr, std::size_t bytes)
    {
        auto* tmp = reinterpret_cast<uint8_t*>(ptr);
        if (tmp + bytes == _ptr)
            _ptr = tmp;
    }
private:
    uint8_t* data() { return reinterpret_cast<uint8_t*>(&_data); }

    std::aligned_storage_t<Bytes, Alignment> _data;
    uint8_t* _ptr;
};

int main()
{

}
