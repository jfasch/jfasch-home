#pragma once

#include <memory>


class SocialInsurance
{
public:
    const std::string& name() const { return _name; }

    virtual void charge(const std::string& id, double euros) = 0;
    virtual double debt(const std::string& id) const = 0;

private:
    std::string _name;

public:
    static SocialInsurance& instance();

protected:
    SocialInsurance(const std::string& name) : _name(name) {}

private:
    static std::unique_ptr<SocialInsurance> _instance;
};
