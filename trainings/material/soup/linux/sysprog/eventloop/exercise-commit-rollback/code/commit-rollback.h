#pragma once

#include "database.h"
#include "eventloop.h"

class CommitRollbackSigHandler : public InputHandler
{
public:
    CommitRollbackSigHandler(Database&);
    ~CommitRollbackSigHandler() override;
    
    void hookup(Eventloop&);
    EventAction ready(int fd) override;

private:
    int _fd;
    Database& _db;
};
