#include <iostream>
#include <map>

using std::cout;
using std::endl;


class User
{
public:
    User() {}
    User(const std::string& firstname, const std::string& lastname)
    : _firstname(firstname), _lastname(lastname) {}

    // read-only access methods for private members (Java: getter methods)
    const std::string& firstname() const { return _firstname; }
    const std::string& lastname() const { return _lastname; }

private:
    std::string _firstname;
    std::string _lastname;
};

int main()
{
    User joerg("Joerg", "Faschingbauer");
    std::string joerg_svnr = "1037190666";

    User caro("Caro", "Faschingbauer");
    std::string caro_svnr = "1234250497";

    User johanna("Johanna", "Faschingbauer");
    std::string johanna_svnr = "2345110695";

    User philipp("Philipp", "Lichtenberger");
    std::string philipp_svnr = "3456060486";

    User datenzwilling_von_joerg("Joerg", "Faschingzwilling");

    std::multimap<std::string, User> meine_map;

    meine_map.insert(std::make_pair(joerg_svnr, joerg));
    meine_map.insert(std::make_pair(caro_svnr, caro));
    meine_map.insert(std::make_pair(johanna_svnr, johanna));

    cout << "initial content:" << endl;
    for (auto elem: meine_map)
        cout << "  Key: " << elem.first << ", Value: " << elem.second.firstname() << ',' << elem.second.lastname() << endl;

    meine_map.insert(std::make_pair(joerg_svnr, datenzwilling_von_joerg));

    cout << "nun haben wir einen datenzwilling:" << endl;
    for (auto elem: meine_map)
        cout << "  Key: " << elem.first << ", Value: " << elem.second.firstname() << ',' << elem.second.lastname() << endl;

    std::multimap<std::string, User>::const_iterator found = meine_map.find(joerg_svnr);

    cout << "found for key " << joerg_svnr << " (using multimap<>.find()) " << endl;
    while (found != meine_map.end() && found->first == joerg_svnr) {
        cout << "Key: " << found->first << ", Value: " << found->second.firstname() << ',' << found->second.lastname() << endl;
        found++;
    }

    {
        cout << "found for key " << joerg_svnr << " (using multimap<>.equal_range()) " << endl;
        // now switching to auto of C++11
        // std::pair<std::multimap<std::string, User>::const_iterator, std::multimap<std::string, User>::const_iterator> found_range = meine_map.equal_range(joerg_svnr);
        auto found_range = meine_map.equal_range(joerg_svnr);
        auto start = found_range.first;
        auto end = found_range.second;
        while (start != end) {
            cout << "Key: " << start->first << ", Value: " << start->second.firstname() << ',' << start->second.lastname() << endl;
            start++;
        }
    }

    {
        std::string svnr_notexist = "1234567";
        cout << "not found for key " << svnr_notexist << " (using multimap<>.equal_range()) " << endl;
        auto found_range = meine_map.equal_range(joerg_svnr);
        auto start = found_range.first;
        auto end = found_range.second;
        if (start == end)
            cout << svnr_notexist << " not found" << endl;
    }

    return 0;
}
