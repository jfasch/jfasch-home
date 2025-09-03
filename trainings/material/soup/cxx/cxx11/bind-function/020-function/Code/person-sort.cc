#include <string>
#include <array>
#include <vector>
#include <algorithm>


class Person
{
public:
    Person(const std::string& firstname, const std::string& lastname)
    : firstname_(firstname),
      lastname_(lastname) {}

    const std::string& firstname() const { return firstname_; }
    const std::string& lastname() const { return lastname_; }

private:
    std::string firstname_;
    std::string lastname_;
};

int main()
{
    std::array<Person, 3> spa{{{"a", "b"}, {"a", "b"}, {"a", "b"}}};

    std::sort(spa.begin(), spa.end(),
              [](const Person& lhs, const Person& rhs) { 
                  return lhs.firstname()<rhs.firstname();
              });
}
