#pragma once

#include <string>
#include <variant>


template <class... Sinks>
class Sink
{
public:
    Sink() = default;

    template <class ConcreteSink>
    Sink(ConcreteSink s)
    : _manyfold(s) {}

    void put(const std::string& str)
    {
        return std::visit(Visitor(str), _manyfold);
    }

private:
    struct Visitor
    {
        Visitor(const std::string& str) : str(str) {}
        void operator()(auto sink) { return sink.put(str); }
        const std::string& str;
    };

private:
    std::variant<Sinks...> _manyfold;
};
