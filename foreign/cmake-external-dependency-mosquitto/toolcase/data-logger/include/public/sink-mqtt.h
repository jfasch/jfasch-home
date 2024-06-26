#pragma once

#include "sink.h"

#include <mosquitto.h>


class MQTTError : public std::exception
{
public:
    MQTTError(const std::string& msg);
    virtual const char* what() const noexcept;
private:
    std::string _msg;
};

class SinkMQTT : public Sink
{
public:
    SinkMQTT(const std::string& host, int port, const std::string& topic);
    ~SinkMQTT();

    void output(const Measurements& data) override;

private:
    std::string _topic;    
    mosquitto* _client;
};
