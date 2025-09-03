#include <iostream>
#include <string>


class Logger
{
public:
    virtual ~Logger() {}
    virtual void log(uint64_t timestamp, std::string message) = 0;
};

class OStreamLogger : public Logger
{
public:
    OStreamLogger(std::ostream& s) : s(s) {}
    virtual void log(uint64_t timestamp, std::string message)
    {
        s << "(OStreamLogger at work) " << timestamp << ':' << message << std::endl;
    }
private:
    std::ostream& s;
};

class DatabaseLogger : public Logger
{
public:
    virtual void log(uint64_t timestamp, std::string message)
    {
        std::cerr << "(DatabaseLogger logging to big fat DB) " << timestamp << ':' << message << std::endl;
    }
};

typedef void(*logfunc_t)(uint64_t timestamp, std::string message);

class FuncPtrLogger : public Logger
{
public:
    FuncPtrLogger(logfunc_t f) : f(f) {}
    virtual void log(uint64_t timestamp, std::string message)
    {
        f(timestamp, message);
    }
private:
    logfunc_t f;
};

class SomeBusinessClassWithNeedForLogging
{
public:
    SomeBusinessClassWithNeedForLogging(Logger* logger) : logger(logger) {}

    void do_much_work()
    {
        logger->log(42, "SomeBusinessClassWithNeedForLogging about to do much work");
        std::cerr << "SomeBusinessClassWithNeedForLogging doing much work" << std::endl;
        logger->log(666, "SomeBusinessClassWithNeedForLogging successfully did much work");
    }

private:
    Logger* logger;
};

void do_stupid_logging(uint64_t timestamp, std::string message)
{
    std::cerr << "do_stupid_logging at work: " << timestamp << ':' << message << std::endl;
}

int main()
{
    OStreamLogger ostream_logger(std::cerr);
    DatabaseLogger database_logger;
    FuncPtrLogger funcptr_logger(&do_stupid_logging);

    SomeBusinessClassWithNeedForLogging busy_logging_to_ostream(&ostream_logger);
    SomeBusinessClassWithNeedForLogging busy_logging_to_database(&database_logger);
    SomeBusinessClassWithNeedForLogging busy_logging_to_funcptr(&funcptr_logger);

    busy_logging_to_ostream.do_much_work();
    busy_logging_to_database.do_much_work();
    busy_logging_to_funcptr.do_much_work();

    return 0;
}
