#include <stdio.h>
#include <stdbool.h>
#include "nic_phys.h"

/*
    Run a loop to ask if the user wants to send or receive with a certain bit pattern
*/
int main(void){
    bool running = true;
    int err;
    char command;
    unsigned char bitpattern;

    while(running){
        // take in input
        // get command
        printf("Enter r to receive, s to send, q to quit:");
        err = scanf(" %c", &command);
        printf("\n");
        // check for errors
        if(err!=1){
            printf("Improper command \n");
        }else{
            // process the commands
            // quit the application
            if(command=='q'){
                running=false;
                break;
            }
            
            if(command=='r'){
                // recv 
                bitpattern = nic_recv();
                printf("Received: %d \n", bitpattern);
                for (unsigned char mask = 0x08; mask != 0; mask>>=1) {
                    printf("%d",(bitpattern & mask ) ? 1:0);
                }
                printf("\n");

            }else if(command=='s'){
                // send
                
                // get bitpattern
                printf("Enter the bitpattern to send (e.g. 1001): \n");
                int holder;
                bitpattern=0;
                for(int i = 0; i<4; i++){
                    printf("Port # %d (0 or 1): ", 4-i);
                    err = scanf(" %d", &holder);
                    if(err!=1){
                        printf("Improper input\n");
                        break;
                    }
                    printf("\n");
                    bitpattern += holder << i;
                }
                nic_send(bitpattern);
            }
        }
    }

}

