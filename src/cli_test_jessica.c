#include <stdio.h>
#include <stdbool.h>
#include "nic_phys.h"

/*
    Run a loop to ask if the user wants to send or receive with a certain bit pattern
*/
int main(void){
    bool running = true;
    int err;
    int choice;
    char recv;
    while(running){
        printf("Enter 0 for send, 1 for recv: ");
        // take in input
        err = scanf("%d", &choice);
        if (err) {
            return 1;
        }
        if (choice) {
            recv = nic_recv();
            for (int i = 0; i < 4; i++) {
                printf("Port %d: %d\n",i + 1,(recv << (4 + i)) >> 7);
            }
        }
        else {
            printf("Enter bits to set transmitters: ");
            err = scanf("%d", &choice);
            if (err) { 
                return 1;
            }
            char bits = choice;
            nic_send(bits);
        }
    }
}

