namespace related_no_virtual
{

double average(auto& sensors)
{
    double sum = 0;
    unsigned long num = 0;
    for (auto& s: sensors) {
        ++num;
        sum += get_temperature(s);
    }
    return sum/num;
}

}
