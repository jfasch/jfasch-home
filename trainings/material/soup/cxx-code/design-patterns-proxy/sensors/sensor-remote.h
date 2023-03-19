#pragma once

#include <sensor.h>
#include <server-thread.h>


class RemoteSensor : public Sensor
{
public:
    RemoteSensor(jf::utilities::ServerThread* server) : _server(server) {}
    virtual double get_temperature() override;
    
private:
    jf::utilities::ServerThread* _server;
};
