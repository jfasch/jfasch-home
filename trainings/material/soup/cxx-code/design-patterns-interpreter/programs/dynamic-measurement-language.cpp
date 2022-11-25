#include <sensor-random.h>
#include <sensor-round.h>
#include <expression.h>

#include <expression-sensorvalue.h>   // <--- to be created

#include <iostream>


int main()
{
    RandomSensor s1(34.3, 40.6);
    RandomSensor s2(35.1, 39.9);
    RandomSensor s3(34.7, 38.8);

    // sensors yield floating point numbers, while the expressions can
    // only do integers. in order to avoid truncation during
    // double->int conversion, we wrap rounding proxies around the raw
    // sensors.
    RoundingSensor r1(&s1);
    RoundingSensor r2(&s2);
    RoundingSensor r3(&s3);

    // a specialized expression (to be implemented) that evaluates
    // itself from sensors.
    SensorValueExpression e1(&r1);    // <--- to be implemented
    SensorValueExpression e2(&r2);    // <--- to be implemented
    SensorValueExpression e3(&r3);    // <--- to be implemented

    // use super-cool expression language on sensors to make
    // measurements and calculate averages
    Addition e1_e2(e1, e2);
    Addition e1_e2_e3(e1_e2, e3);
    Literal num_measurements(3);
    Division average(e1_e2_e3, num_measurements);

    // create variable in context, and evaluate average into it
    Context context;
    Variable v_avg(context, "avg");
    Assignment v_ass(v_avg, average);

    std::cout << v_ass.evaluate() << std::endl;

    return 0;
}
