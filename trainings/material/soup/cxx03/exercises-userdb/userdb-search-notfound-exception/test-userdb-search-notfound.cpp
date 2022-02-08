#include "userdb.h"
#include <iostream>

int main()
{
    UserDB db;

    try {
        User user = db.search_by_lastname("Faschingbauer");

        // unreached because database is empty
        std::cout << "yay!" << user.lastname() << std::endl;
        return 0;
    }
    except (const UserNotFound& e) {
        std::cerr << "argh: no \"Faschingbauer\" in there" << std::endl;
        return 1;
    }
}
