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
            for (unsigned char mask = 0x08; mask != 0; mask>>=1) {
                //print the last four binary digits of the char, which are the relevant digits
                printf("Port %d: %d\n",i + 1,(recv & mask) ? 1: 0);
            }
        }
        else {
            printf("Enter bits to set transmitters: ");
            char input[4];
            scanf("%s", &input);
            int binarychoice = 0;
            for (int i = 0; i < 4; i++) {
                binarychoice += 2 ** i * (input[i] == '1');
            char bits = binarychoice;
            nic_send(bits);
        }
    }
}

