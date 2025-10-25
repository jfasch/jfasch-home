#include "database.h"
#include "eventloop.h"
#include "udp-db.h"
#include "stdin-db.h"
#include "graceful-term.h"

int main()
{
    Eventloop loop;                                    // <-- main loop
    Database db;

    UDPToDatabase udp("0.0.0.0", 1234, db);            // <-- satellite
    StdinToDatabase stdin(db);                         // <-- satellite
    GracefulTerminator terminator;                     // <-- satellite

    udp.hookup(loop);                                  // <-- register with loop
    stdin.hookup(loop);                                // <-- register with loop
    terminator.hookup(loop);                           // <-- register with loop

    loop.run();                                        // <-- run until quit

    db.commit();
    return 0;
};
