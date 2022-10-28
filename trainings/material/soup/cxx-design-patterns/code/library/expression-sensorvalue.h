#pragma once

#include "expression.h"
#include "sensor.h"


class SensorValueExpression : public Expression
{
public:
    SensorValueExpression(Sensor* sensor) : _sensor(sensor) {}

    int evaluate() override;

private:
    Sensor* _sensor;
};
