bool might_fail()
{
    return false;
}

int main()
{
    might_fail();                                      // <-- potential error not handled
    return 0;                                          // <-- ... though exit OK
}
