//test program to print recieved values to the screen, quickly.
//hacked together, not production code.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nic_phys.h"
//takes in a port num to monitor (1-4)
int main(int argc, char *argv[]) {
	nic_init();
	//not resilient. crashes with cli input
	char *portStr = argv[1];
	int num = atoi(portStr);
	while (1) {
		char data = nic_recv();
		char value = 0;
		//printf("%d\n",data);
		if (num == 1) {
			value = (data&0b00001000)>>3;
		}
		else if (num == 2) {
			value = (data&0b00000100)>>2;
		}
		else if (num == 3) {
			value = (data&0b00000010)>>1;
		}
		else if (num ==4) {
			value = (data&0b00000001);
		}
		else {
			printf("wrong port entered\n");
			break;
		}
		printf("Port %d: %d\n",num,value);
	}
}
