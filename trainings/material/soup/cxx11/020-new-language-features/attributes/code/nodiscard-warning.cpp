[[nodiscard]] bool might_fail()
{
    return false;
}

int main()
{
    might_fail();                                      // <-- warning: ignoring return value of ‘bool might_fail()’, declared with attribute ‘nodiscard’
    return 0;
}
