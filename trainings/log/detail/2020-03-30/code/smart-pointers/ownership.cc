#include "employee.h"

#include <gtest/gtest.h>

#include <string>
#include <iostream>
#include <memory>

using namespace std;


// ------------------------------------------------------------------
// PRIMITIVE

// manager records employee pointers in a vector. no ownership defined
// at all. who deletes the employee is only a matter of coffee talk of
// two programmers.
// ------------------------------------------------------------------
class PrimitiveManager
{
public:
    ~PrimitiveManager()
    {
        for (std::vector<EmployeeRecord*>::size_type i=0; i<_employees.size(); i++)
            delete _employees[i];
    }

    size_t num_employees() const { return _employees.size(); }

    void add_employee(EmployeeRecord* emp)
    {
        _employees.push_back(emp);
    }

    void assess_employees()
    {
        for (std::vector<EmployeeRecord*>::size_type i=0; i<_employees.size(); i++)
            _employees[i]->add_comment("super");
    }

private:
    std::vector<EmployeeRecord*> _employees;
};

TEST(Ownership, Primitive)
{
    EmployeeRecord* alex = new EmployeeRecord("Alexander", "Cristea");
    EmployeeRecord* jakob = new EmployeeRecord("Jakob", "Gegeniger");

    PrimitiveManager martin;
    martin.add_employee(alex);
    martin.add_employee(jakob);

    martin.assess_employees();

    ASSERT_EQ(alex->num_comments(), 1);
    ASSERT_EQ(jakob->num_comments(), 1);

    ASSERT_EQ(martin.num_employees(), 2);
}


// ------------------------------------------------------------------
// SMART (shared_ptr)

// manager records employee pointers as shared_ptr<> instances,
// thereby freeing anybody from having to have an ownership
// definition. this is rather decadent, but an easy and correct thing
// to do in most situation. 

// note though that it is possible to create cyclic references, which
// result in a memory leak!
// ------------------------------------------------------------------
class SmartManager
{
public:
    size_t num_employees() const { return _employees.size(); }

    void add_employee(std::shared_ptr<EmployeeRecord> emp)
    {
        _employees.push_back(emp);
    }

    void assess_employees()
    {
        for (std::vector<EmployeeRecord*>::size_type i=0; 
             i<_employees.size(); 
             i++)
            _employees[i]->add_comment("super");
    }

private:
    std::vector<std::shared_ptr<EmployeeRecord>> _employees;
};

TEST(Ownership, Smart)
{
    std::shared_ptr<EmployeeRecord> alex(new EmployeeRecord("Alexander", "Cristea"));
    std::shared_ptr<EmployeeRecord> jakob(new EmployeeRecord("Jakob", "Gegeniger"));

    {
        SmartManager martin;
        martin.add_employee(alex);
        martin.add_employee(jakob);

        martin.assess_employees();

        ASSERT_EQ(martin.num_employees(), 2);
    }

    ASSERT_EQ(alex->num_comments(), 1);
    ASSERT_EQ(jakob->num_comments(), 1);

    // gessmann plays tricks with naked memory
    EmployeeRecord* alex_cptr = alex.get();
#if 0
    delete alex_cptr;   // EVIL!!
#else
    (void)alex_cptr;
#endif
    
    // gessmann does not want to care anymore
    alex.reset();
    jakob.reset();
}



// ------------------------------------------------------------------
// UNIQUE (unique_ptr)

// exclusive ownership: manager record employees as unique_ptr<>
// instance. this way the compiler can force everybody who's involved
// to define clear ownership. for example, when somebody assigns an
// employee to the manager, one has to explicitly state the fact that
// ownership is being transferred by saying
// "add_employee(std::move(employee))"

// (C++ "move semantics" makes this possible)
// ------------------------------------------------------------------
class UniqueManager
{
public:
    size_t num_employees() const { return _employees.size(); }

    void add_employee(std::unique_ptr<EmployeeRecord> emp)
    {
        _employees.push_back(std::move(emp));
    }

    std::unique_ptr<EmployeeRecord> take_employee(const std::string& firstname, const std::string& lastname)
    {
        for (auto it = _employees.begin(); it != _employees.end(); it++)
            if ((*it)->firstname() == firstname && (*it)->lastname() == lastname) {
                std::unique_ptr<EmployeeRecord> ret = std::move(*it);
                _employees.erase(it);
                return ret;
            }
        return std::unique_ptr<EmployeeRecord>();
    }

    void assess_employees()
    {
        for (std::vector<EmployeeRecord*>::size_type i=0; 
             i<_employees.size(); 
             i++)
            _employees[i]->add_comment("super");
    }

private:
    // using xxx = std::vector<std::unique_ptr<EmployeeRecord>>;
    std::vector<std::unique_ptr<EmployeeRecord>> _employees;
};

TEST(Ownership, Unique)
{
    std::unique_ptr<EmployeeRecord> alex(new EmployeeRecord("Alexander", "Cristea"));
    std::unique_ptr<EmployeeRecord> jakob(new EmployeeRecord("Jakob", "Gegeniger"));

    UniqueManager martin;
    UniqueManager herbert;

    // clear ownership transfer
    martin.add_employee(std::move(alex));
    martin.add_employee(std::move(jakob));

    // gessmann has no possibility to disturb alex while he's working
    // for martin.
    ASSERT_EQ(alex.get(), nullptr);
    // ASSERT_EQ(alex->num_comments(), 0);

    martin.assess_employees();

    // pass alex on from martin to herbert
    alex = martin.take_employee("Alexander", "Cristea");
    ASSERT_EQ(martin.num_employees(), 1);

    ASSERT_EQ(herbert.num_employees(), 0);
    herbert.add_employee(std::move(alex));
    ASSERT_EQ(herbert.num_employees(), 1);
    herbert.assess_employees();

    alex = herbert.take_employee("Alexander", "Cristea");
    ASSERT_EQ(alex->num_comments(), 2);
}
