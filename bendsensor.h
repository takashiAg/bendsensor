#ifndef BEND_H_INCLUDE
#define BEND_H_INCLUDE

#include "Arduino.h"




class bendsensor {
  public:
    bendsensor();
    void init(uint8_t pin);
    uint16_t read();
    uint16_t read_normalized();
    uint16_t read_raw();

  private:

    uint8_t __pin;
    const uint16_t resister = 47000;
    const uint16_t ANALOG_REFERENCE = 3300;
    const uint16_t ANALOG_RANGE = 4096;

};


#endif



