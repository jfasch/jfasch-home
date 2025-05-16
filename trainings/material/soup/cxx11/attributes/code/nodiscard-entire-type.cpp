enum class [[nodiscard]] Error
{
    OK,
    FAILED,
    NONSENSE,
    // ...
};


Error might_fail()
{
    return Error::FAILED;
}

int main()
{
    Error e = might_fail();
    return (e == Error::OK)?0:1;
}
