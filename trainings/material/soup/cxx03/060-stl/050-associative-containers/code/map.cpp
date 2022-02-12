#include <iostream>
#include <map>
using namespace std;


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

    std::map<std::string, User> meine_user_db;

    // insert (using index operator)
    meine_user_db[joerg_svnr] = joerg;
    meine_user_db[johanna_svnr] = johanna;
    meine_user_db[caro_svnr] = caro;

    cout << "initial content: " << endl;
    for (auto elem: meine_user_db)
        cout << "   Key: " << elem.first << ", Value: " << elem.second.firstname() << ',' << elem.second.lastname() << endl;

    meine_user_db[joerg_svnr] = caro;

    cout << "content after overwrite: " << endl;
    for (auto elem: meine_user_db)
        cout << "   Key: " << elem.first << ", Value: " << elem.second.firstname() << ',' << elem.second.lastname() << endl;


    // insert (using map::insert())
    {
        // no error: philipp not yet in db
        meine_user_db.insert(std::make_pair(philipp_svnr, philipp));

        // error: johanna already there (doc says that the operation
        // fails)
        std::pair<std::map<std::string, User>::iterator, bool> returnvalue =
            meine_user_db.insert(std::make_pair("2345110695", User("xyz", "abc")));
        if (returnvalue.second == true)
            cout << "operation successful" << endl;
        else {
            cout << "operation not successful, a user with this key already exists:" << endl;
            cout << "  Firstname: " << returnvalue.first->second.firstname() << endl;
            cout << "  Lastname: " << returnvalue.first->second.lastname() << endl;
        }
    }

    cout << meine_user_db.size() << endl;

    // search (using index operator)
    {
        User joerg = meine_user_db[joerg_svnr];
        cout << joerg.firstname() << endl;
        cout << joerg.lastname() << endl;
    }

    // search the same, but with a key that does not exist
    {
        User somebody = meine_user_db["5678010101" /*not an existing key*/];
        cout << somebody.firstname() << endl;  // empty string
        cout << somebody.lastname() << endl;

        if (somebody.firstname() == "" && somebody.lastname() == "")
            cout << "5678010101 not found (but created as side effect)" << endl;
        else {
            cout << "Firstname: " << somebody.firstname() << endl;
            cout << "Lastname: " << somebody.lastname() << endl;
        }
        
        // GOTCHA: the map has been modified: an empty User has been
        // inserted under that key.
    }

    // search using at(), with a key that does not exist
    {
        try {
            User somebody = meine_user_db.at("6789020222"/*does not exist*/);
            cout << "Firstname: " << somebody.firstname() << endl;
            cout << "Lastname: " << somebody.lastname() << endl;
        }
        catch (const std::out_of_range&) {
            cerr << "6789020222 not found" << endl;
        }
    }

    return 0;
}
