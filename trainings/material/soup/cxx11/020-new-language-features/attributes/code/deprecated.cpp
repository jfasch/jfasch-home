[[deprecated]] void old_crap()
{
    // ...
}

[[deprecated("this is crap")]] void old_crap2()
{
    // ...
}

int main()
{
    old_crap();                                        // <-- warning: ‘void old_crap()’ is deprecated
    old_crap2();                                       // <-- warning: ‘void old_crap2()’ is deprecated: this is crap
    return 0;
}
