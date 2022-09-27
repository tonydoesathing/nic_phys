#include <pigpiod_if2.h>
#include <stdint.h>

//define ports. broadcom nums. port 1 is idx 0.
static int in_array[] = {26, 24, 22, 20};
static int out_array[] = {27, 25, 23, 21};


nic_send(char input) {
	int pi = pigpio_start(NULL,NULL);
	//set modes using a loop
	for (int i = 0; i<4; i++) {
		set_mode(pi, out_array[i], PI_OUTPUT);
		set_mode(pi, in_array[i], PI_INPUT);
	}
	//set ports to their passed values
	gpio_write(pi,in_array[0],(input&b00001000)>>3);
	gpio_write(pi,in_array[0],(input&b00000100)>>2);
	gpio_write(pi,in_array[0],(input&b00000010)>>1);
	gpio_write(pi,in_array[0],(input&b00000001));
	
}
