#include <stdio.h>
#include <pigpiod_if2.h>
#include <pigpio.h>

static int in_array[] = {26, 24, 22, 20};
static int out_array[] = {27, 25, 23, 21};

void nic_recv() {
        char result = 0b00000000;
        int i = 0;
        for (i; i < 4; i++) {
                
        }

}

int main() {
	printf("Hello World!\n");
	//gpioInitialise();
	//port 1
	//tx:13
	//rx:37
	int pi = pigpio_start(NULL,NULL);
	int err = set_mode(pi, 27, PI_OUTPUT);
	printf("set mode returns %d\n",err);
	printf("port 1 started with:%d\n",gpio_read(pi,26));
	int sendVal = 1;
	gpio_write(pi,27,sendVal);
	printf("port 1 recieved:%d\n",gpio_read(pi,26));
	sleep(1);
	printf("after 1s, port 1 holds:%d\n",gpioRead(pi,26));
	return 0;
}
