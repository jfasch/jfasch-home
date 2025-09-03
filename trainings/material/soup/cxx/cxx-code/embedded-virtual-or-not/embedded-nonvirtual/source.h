#pragma once

#include <string>
#include <variant>


template <class... Sources>
class Source
{
public:
    Source() = default;

    template <class ConcreteSource>
    Source(ConcreteSource s)
    : _manyfold(s) {}

    std::string get()
    {
        return std::visit(Visitor(), _manyfold);
    }

private:
    struct Visitor
    {
        std::string operator()(auto source) { return source.get(); }
    };

private:
    std::variant<Sources...> _manyfold;
};
