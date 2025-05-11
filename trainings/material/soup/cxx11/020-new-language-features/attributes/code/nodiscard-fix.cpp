[[nodiscard]] bool might_fail()
{
    return false;
}

int main()
{
    bool ok = might_fail();
    return ok?0:1;
}
