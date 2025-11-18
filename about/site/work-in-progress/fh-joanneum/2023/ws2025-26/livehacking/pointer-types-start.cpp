#include <vector>
#include <random>
#include <print>

class Sensor
{
public:
    virtual ~Sensor() {}
    virtual double get_value() = 0;
};

class MockSensor : public Sensor
{
public:
    MockSensor(double initial_value) : _value{initial_value} {}
    double get_value() override { return _value; }
    // for tests only
    void set_value(double v) { _value = v; }
private:
    double _value;
};

class RandomSensor : public Sensor
{
public:
    RandomSensor(double low, double high)
    : _distribution(std::uniform_real_distribution<double>(low, high)),
      _engine(std::random_device()()) {}

    virtual double get_value() override
    {
        return _distribution(_engine);
    }

private:
    std::uniform_real_distribution<double> _distribution;
    std::default_random_engine _engine;
};

class Averager
{
public:
    Averager(Sensor* left, Sensor* right)
    : _left(left), _right(right) {}

    double get_average() { return (_left->get_value() + _right->get_value()) / 2; }

private:
    Sensor* _left;
    Sensor* _right;
};


int main(int argc, char** argv)
{
    std::string how = argv[1];

    MockSensor left(2.0);
    MockSensor right(7.5);

    Averager avg(&left, &right);

    double v = avg.get_average();
    std::println("Average value: {}", v);

    return 0;
}
