#include "big-data.h"

#include <map>
#include <memory>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std::chrono_literals;


int main()
{
    std::map<std::string, std::shared_ptr<BigData>> datasets;
    datasets["dataset-a"] = std::make_shared<BigData>(100, 'a');
    datasets["dataset-b"] = std::make_shared<BigData>(100, 'b');
    datasets["dataset-c"] = std::make_shared<BigData>(100, 'c');

    std::weak_ptr<BigData> maybe_dataset =             // <-- might vanish
        datasets["dataset-b"];

    std::thread crunch_thread([maybe_dataset]() {
        while (true) {
            if (auto dataset = maybe_dataset.lock(); dataset) {
                std::cout << "now crunching dataset" << std::endl;
                std::this_thread::sleep_for(700ms);
            }
            else {
                std::cout << "terminating" << std::endl;
                break;
            }
        }
    });

    // after 2 seconds the dataset vanishes
    std::this_thread::sleep_for(2s);
    std::cout << "removing dataset" << std::endl;
    datasets.erase("dataset-b");

    crunch_thread.join();

    return 0;
}
