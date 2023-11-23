#include "unrelated.h"

#include <benchmark/benchmark.h>

#include <vector>
#include <memory>


static void Unrelated(benchmark::State& state) {
    unrelated::Sensor1 s1{37.5};
    unrelated::Sensor2 s2{42.666};

    for (auto _ : state) {
        s1.get_temperature();
        s2.get_temperature();
    }
}
BENCHMARK(Unrelated);
