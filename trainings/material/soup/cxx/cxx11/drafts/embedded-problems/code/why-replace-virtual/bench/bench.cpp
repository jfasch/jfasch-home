#include "avg.h"

#include <unistd.h>

#include <benchmark/benchmark.h>
#include <memory>
#include <vector>


static void naive(benchmark::State& state) {
    double start = 0;
    std::vector<std::shared_ptr<Sensor>> sensors;
    for (int i=0; i<10000; i++) {
        if (i%2 == 0)
            sensors.push_back(std::make_shared<Sensor1>(start));
        else
            sensors.push_back(std::make_shared<Sensor2>(start));
        ++start;
    }

    for (auto _ : state) {
        auto avg = average(sensors);
        (void)avg;
    }
}
BENCHMARK(naive);

template <typename SensorType>
std::shared_ptr<SensorType> make_evil_sensor(double temperature)
{
    // void* mem = std::aligned_alloc(alignof(SensorType), sizeof(SensorType)); // ???? 128? 256?
    void* mem = std::malloc(sizeof(SensorType));    // slooooow
    SensorType* ptr = new (mem) SensorType(temperature);
    return std::shared_ptr<SensorType>(ptr, [](auto mem) { std::free(mem); });
}

static void evil(benchmark::State& state) {
    double start = 0;
    std::vector<std::shared_ptr<Sensor>> sensors;
    for (int i=0; i<100000; i++) {
        if (i%2 == 0)
            sensors.push_back(make_evil_sensor<Sensor1>(start));
        else
            sensors.push_back(make_evil_sensor<Sensor2>(start));
        ++start;
    }

    for (auto _ : state) {
        auto avg = average(sensors);
        (void)avg;
    }
}
BENCHMARK(evil);

BENCHMARK_MAIN();
