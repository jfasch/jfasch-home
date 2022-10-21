#pragma once

#include <iostream>
#include <map>


class SocialInsurance
{
public:
    const std::string& name() const { return _name; }
    void charge(const std::string& id, double euros);
    double debt(const std::string& id) const;

private:
    std::string _name;
    std::map<std::string, double> _database;

public:
    static SocialInsurance& instance();

    SocialInsurance(const SocialInsurance&) = delete;
    SocialInsurance& operator=(const SocialInsurance&) = delete;

private:
    SocialInsurance(const std::string& name) : _name(name) {}
    static SocialInsurance _instance;
};
