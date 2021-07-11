#include <iostream>
#include <string>
#include <functional>



class DatabaseLogger
{
public:
    void do_the_heavy_logging(const char *message)
    {
        std::cerr << "heavy database log: " << message << std::endl;
    }
};

void do_stupid_logging(uint64_t timestamp, std::string message)
{
    std::cerr << "do_stupid_logging at work: " << timestamp << ':' << message << std::endl;
}



using logger_t = std::function<void(uint64_t,std::string)>;

class SomeBusinessClassWithNeedForLogging
{
public:
    SomeBusinessClassWithNeedForLogging(logger_t l) : logger(l) {}

    void do_much_work()
    {
        logger(42, "SomeBusinessClassWithNeedForLogging about to do much work");
        std::cerr << "SomeBusinessClassWithNeedForLogging doing much work" << std::endl;
        logger(666, "SomeBusinessClassWithNeedForLogging successfully did much work");
    }

private:
    logger_t logger;
};

int main()
{
    DatabaseLogger database_logger;
    std::ostream& s = std::cerr;

    SomeBusinessClassWithNeedForLogging busy_logging_to_ostream(
        logger_t([&s](uint64_t timestamp, std::string message) {
                s << "(OStreamLogger at work) " << timestamp << ':' << message << std::endl;
            }));
    SomeBusinessClassWithNeedForLogging busy_logging_to_database(
        logger_t(std::bind(&DatabaseLogger::do_the_heavy_logging, &database_logger, std::placeholders::_2)));
    SomeBusinessClassWithNeedForLogging busy_logging_to_funcptr(
        logger_t(std::bind(do_stupid_logging, std::placeholders::_1, std::placeholders::_2)));

    busy_logging_to_ostream.do_much_work();
    busy_logging_to_database.do_much_work();
    busy_logging_to_funcptr.do_much_work();

    return 0;
}
