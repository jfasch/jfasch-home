int main()
{
    int& i;
    i = 666; //   <--- only potentially evil
    return 0;
}
