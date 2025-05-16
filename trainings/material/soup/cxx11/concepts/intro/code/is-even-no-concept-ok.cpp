template <typename T>
bool is_even(T num)
{
    return (num % 2) == 0;
}
   
int main()
{
    is_even(3);
    is_even(4UL);
    is_even(4L);
    return 0;
}
