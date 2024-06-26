#include "sink-mqtt.h"

#include <cassert>
#include <string.h>


MQTTError::MQTTError(const std::string& msg)
: _msg(msg) {}

const char* MQTTError::what() const noexcept
{
    return _msg.c_str();
}

SinkMQTT::SinkMQTT(const std::string& host, int port, const std::string& topic)
: _topic(topic)
{
    _client = mosquitto_new(
        "Gluehweinkochen", // id
        false,             // clean_session
        nullptr            // obj
    );
    if (_client == nullptr) {
        int err = errno;
        std::string msg = "mosquitto_new: ";
        msg += strerror(err);
        throw MQTTError(msg);
    }

    int error = mosquitto_connect(_client, host.c_str(), port, /*keepalive*/10);
    if (error != MOSQ_ERR_SUCCESS) {
        assert(error != MOSQ_ERR_INVAL);
        // must be MOSQ_ERR_ERRNO, according to documentation
        int err = errno;
        std::string msg = "mosquitto_new: ";
        msg += strerror(err);
        throw MQTTError(msg);
    }
}

SinkMQTT::~SinkMQTT()
{
    mosquitto_destroy(_client);
}

void SinkMQTT::output(const Measurements& data)
{
    // create json like string
    std::string msg = "{";
    for (const auto& [name, value] : data)
    {
        msg += " \"";
        msg += name;
        msg += "\" : ";
        msg += std::to_string(value);
        msg += ",";
    }
    msg.pop_back();
    msg += " }";

    int error = mosquitto_publish(_client, nullptr, _topic.c_str(), msg.size(), msg.c_str(), /*qos*/0, /*retain*/false);
    if (error != MOSQ_ERR_SUCCESS)
        throw MQTTError(mosquitto_strerror(error));
}
