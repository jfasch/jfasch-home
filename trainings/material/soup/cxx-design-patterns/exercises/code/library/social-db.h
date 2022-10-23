#pragma once

#include <string>
#include <map>
#include <exception>
#include <initializer_list>


class SocialDB
{
public:
    class Error : public std::exception
    {
    public:
        Error(const std::string& msg) : _msg(msg) {}
        const std::string& msg() const { return _msg; }
        virtual const char* what() const noexcept { return _msg.c_str(); }

    private:
        std::string _msg;
    };
    class NotInserted : public Error
    {
    public:
        NotInserted(const std::string& msg) : Error(msg) {}
    };
    class NotFound : public Error 
    {
    public:
        NotFound(const std::string& msg) : Error(msg) {}
    };

    using Person = std::pair<std::string/*firstname*/, std::string/*lastname*/>;
    using db = std::map<std::string/*svnr*/, Person>;

public:
    SocialDB() = default;
    SocialDB(std::initializer_list<std::pair<const std::string, Person>>);

    size_t size() const { return _db.size(); }
    void insert(const std::string& svnr, const std::string& firstname, const std::string& lastname);
    const Person& find(const std::string& svnr) const;
    void drop() { _db.clear(); }

public:
    // for testing only
    const db& database() const { return _db; }

private:
    db _db;
};
