#include "bendsensor.h"
bendsensor::bendsensor() {}

void bendsensor::init(uint8_t pin) {
  __pin = pin;
}
uint16_t bendsensor::read_raw() {
  return analogRead(__pin);
}

uint16_t bendsensor::read_normalized() {
  static boolean is_read_firsttime = true;
  static uint16_t min, max;

  uint16_t raw_value = read_raw();

  min = is_read_firsttime ? raw_value : ( raw_value < min ? min : raw_value);
  max = is_read_firsttime ? raw_value : ( raw_value > max ? max : raw_value);

  is_read_firsttime = false;


  uint16_t normalized_value = min == raw_value ? 0 : map(raw_value, min, max, 0, 1000);

  return normalized_value;

}

uint16_t bendsensor::read() {
  uint32_t raw_value = (uint32_t)read_raw();
  uint16_t voltage = (raw_value * ANALOG_REFERENCE ) / ANALOG_RANGE;

  return voltage;
}
