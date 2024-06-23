#pragma once

#include "sink.h"

#include <fstream>
#include <iostream>


class SinkFile : public Sink
{
public:
    explicit SinkFile(const std::string& filename);
    ~SinkFile() override;

    void output(const Measurements& data) override;

private:
    std::ofstream _file;
};
