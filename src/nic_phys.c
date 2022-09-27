#include <pigpiod_if2.h>
#include <stdint.h>
//bad design to so a char?
nic_send(char input) {
	int pi = pigpio_start(NULL,NULL);
        int err = set_mode(pi, 27, PI_OUTPUT);

}
