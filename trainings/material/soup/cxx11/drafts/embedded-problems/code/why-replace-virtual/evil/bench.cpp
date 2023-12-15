#include "avg.h"

#include <benchmark/benchmark.h>
#include <memory>
#include <vector>


static void naive(benchmark::State& state) {
    std::vector<std::shared_ptr<Sensor>> sensors{
        std::make_shared<Sensor1>(37.4),
        std::make_shared<Sensor2>(666.8),
        std::make_shared<Sensor1>(-273.15),
        std::make_shared<Sensor2>(3.141),
        std::make_shared<Sensor1>(42.1),
        std::make_shared<Sensor2>(42.2),
    };

    for (auto _ : state) {
        auto avg = average(sensors);
        (void)avg;
    }
}

BENCHMARK(naive);

BENCHMARK_MAIN();
