#include <AP_Common.h>
#include <AP_Math.h>
#include <AP_Param.h>
#include <AP_Progmem.h>

#include <AP_HAL.h>
#include <AP_HAL_AVR.h>
#include <AP_HAL_AVR_SITL.h>
#include <AP_HAL_PX4.h>
#include <AP_HAL_Empty.h>

# define RELEASE_WIRE_R1         10.0
# define RELEASE_WIRE_R2         4.7

const AP_HAL::HAL& hal = AP_HAL_BOARD_DRIVER;

AP_HAL::AnalogSource* ch;
AP_HAL::AnalogSource* release_wire_status;

void setup (void) {
  ch = hal.analogin->channel(3);
  release_wire_status = hal.analogin->channel(5);
}

static int8_t pin;

void loop (void){
  ch->set_pin(3);
  float v  = ch->voltage_average(); 

  //hal.console->printf_P(PSTR("Celsius: %.2f"), ((v*100)-273.15));
  //hal.console->println();

  hal.scheduler->delay(100);

  //release_wire_status->set_pin(5);
  float val = release_wire_status->voltage_average(); 
  hal.console->printf_P(PSTR("%.3f"), val);
  hal.console->println();
  hal.console->printf_P(PSTR("%.2f"), (val*(RELEASE_WIRE_R1+RELEASE_WIRE_R2)/RELEASE_WIRE_R2));

  hal.console->println();
  hal.console->println();

  hal.scheduler->delay(400);
}

AP_HAL_MAIN();








