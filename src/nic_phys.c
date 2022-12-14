#include <pigpiod_if2.h>
#include <stdint.h>
#include "nic_phys.h"

//define ports. broadcom nums. port 1 is idx 0.
static int in_array[] = {26, 24, 22, 20};
static int out_array[] = {27, 25, 23, 21};
static int pi;

//input structure: 4 least sig bits of char
//1 0 0 1 : turns on port 1 and 4, turns off 2 and 3
void nic_send(char input) {
	//set ports to their passed values
	gpio_write(pi,out_array[0],(input&0b00001000)>>3);
	gpio_write(pi,out_array[1],(input&0b00000100)>>2);
	gpio_write(pi,out_array[2],(input&0b00000010)>>1);
	gpio_write(pi,out_array[3],(input&0b00000001));
	
}

//Check and return the state of all receivers
//Returns a char value with the last four bits representing the receiver states
//Return format: 0b0000<port1><port2><port3><port4> e.g. 0b00001001
char nic_recv() {
        char result = 0b00000000;
        char state;
        for (int i = 0; i < 4; i++) {
                state = gpio_read(pi, in_array[i]);
                result = result | (state << (3 - i));
        }
        return result;
}


void nic_init() {
	pi = pigpio_start(NULL,NULL);
	
	//set modes using a loop
	for (int i = 0; i<4; i++) {
		set_mode(pi, out_array[i], PI_OUTPUT);
		set_mode(pi, in_array[i], PI_INPUT);
	}

}
