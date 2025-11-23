#include <string>
#include <vector>
#include <random>
#include <print>
#include <memory>
#include <iostream>

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
    Averager(std::shared_ptr<Sensor> left, std::shared_ptr<Sensor> right)
    : _left(left), _right(right) {}

    double get_average() { return (_left->get_value() + _right->get_value()) / 2; }

private:
    std::shared_ptr<Sensor> _left;
    std::shared_ptr<Sensor> _right;
};

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::println(stderr, "nix wie gegeben (mock|random)");
        return 1;
    }

    std::string how = argv[1];

    std::shared_ptr<Sensor> left;
    std::shared_ptr<Sensor> right;

    if (how == "mock") {
        left = std::shared_ptr<MockSensor>(new MockSensor(2.0));
        right = std::shared_ptr<MockSensor>(new MockSensor(7.5));
    }
    else if (how == "random") {
        left = std::shared_ptr<RandomSensor>(new RandomSensor(1.5, 2.5));
        right = std::shared_ptr<RandomSensor>(new RandomSensor(-273.15, 6000000000));
    }
    else {
        std::println("nix mock oder random");
        return 1;
    }

    Averager avg(left, right);

    double v = avg.get_average();
    std::println("Average value: {}", v);

    return 0;
}
