#ifndef __HAVE_EMPLOYEE_H__
#define __HAVE_EMPLOYEE_H__

#include <vector>
#include <string>
#include <unistd.h>


class EmployeeRecord
{
public:
    EmployeeRecord(const std::string& firstname, const std::string& lastname)
    : _firstname(firstname), _lastname(lastname) {}

    const std::string firstname() const { return _firstname; }
    const std::string lastname() const { return _lastname; }
    void add_comment(const std::string& comment) { _comments.push_back(comment); }
    size_t num_comments() const { return _comments.size(); }

private:
    std::string _firstname;
    std::string _lastname;
    std::vector<std::string> _comments;
};

#endif
