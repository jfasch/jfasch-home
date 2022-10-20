#pragma once

#include "sensor.h"
#include "server-thread.h"


class RemoteSensorAdapter : public ServerThread::RemoteAdapter
{
public:
    RemoteSensorAdapter(Sensor* sensor) : _sensor(sensor) {}
    virtual std::string execute(const std::string& request) override;

private:
    Sensor* _sensor;
};
