#pragma once

#include <sensor.h>
#include <server-thread.h>


class RemoteSensor : public Sensor
{
public:
    RemoteSensor(ServerThread* server) : _server(server) {}
    virtual double get_temperature() override;
    
private:
    ServerThread* _server;
};
