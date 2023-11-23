#include "classic-virtual.h"

#include <benchmark/benchmark.h>

#include <vector>
#include <memory>


static void ClassicVirtual_Single(benchmark::State& state) {
    classic_virtual::Sensor1 s1{37.5};
    classic_virtual::Sensor2 s2{42.666};

    classic_virtual::Sensor* s1p = &s1;
    classic_virtual::Sensor* s2p = &s2;

    for (auto _ : state) {
        s1p->get_temperature();
        s2p->get_temperature();
    }
}
BENCHMARK(ClassicVirtual_Single);

static void ClassicVirtual_VectorSharedPtr(benchmark::State& state) {
    std::vector<std::shared_ptr<classic_virtual::Sensor>> sensors = {
        std::make_shared<classic_virtual::Sensor1>(37.5),
        std::make_shared<classic_virtual::Sensor2>(42.666),
    };

    for (auto _ : state)
        for (auto& s: sensors)
            s->get_temperature();
}
BENCHMARK(ClassicVirtual_VectorSharedPtr);

static void ClassicVirtual_VectorPtr(benchmark::State& state) {
    classic_virtual::Sensor1 s1{37.5};
    classic_virtual::Sensor2 s2{42.666};

    std::vector<classic_virtual::Sensor*> sensors = {
        &s1,
        &s2,
    };

    for (auto _ : state)
        for (auto s: sensors)
            s->get_temperature();
}
BENCHMARK(ClassicVirtual_VectorPtr);
