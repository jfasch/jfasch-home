#include "employee.h"

#include <vector>
#include <algorithm>
#include <iostream>



static bool less(const EmployeeRecord& lhs, const EmployeeRecord& rhs)
{
    if (lhs.lastname() < rhs.lastname())
        return true;
    if (lhs.lastname() > rhs.lastname())
        return false;
    return lhs.firstname() < rhs.firstname();
}

static bool reverse_firstname(const EmployeeRecord& lhs, const EmployeeRecord& rhs)
{
    if (lhs.firstname() > rhs.firstname())
        return true;
    if (lhs.firstname() < rhs.firstname())
        return false;
    return lhs.lastname() > rhs.lastname();
}


int main()
{
    std::vector<EmployeeRecord> employees;
    employees.push_back(EmployeeRecord("Jakob", "Gegeniger"));
    employees.push_back(EmployeeRecord("Alexander", "Cristea"));

    std::sort(employees.begin(), employees.end(), less);

    std::cout << "last,first(asc):" << std::endl;
    for (auto em: employees)
        std::cout << em.firstname() << ' ' << em.lastname() << std::endl;

    std::sort(employees.begin(), employees.end(), reverse_firstname);

    std::cout << "first,last(desc):" << std::endl;
    for (auto em: employees)
        std::cout << em.firstname() << ' ' << em.lastname() << std::endl;

    return 0;
}
