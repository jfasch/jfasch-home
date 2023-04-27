from sensors.sensor_const import ConstantSensor
import pytest

def test_basic():
    sensor = ConstantSensor(36.7)
    temperature = sensor.get_temperature()
    assert temperature == pytest.approx(36.7)
