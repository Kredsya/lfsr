/**
 * This program is for 1st problem of CryptContest 2024.
 * m = 128 (number of flip-flop)
 * feedback coefficients = (0, 1, 2, 7, 128)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void usage() {
    printf("usage : ./lfsr <1:how many generate> <2:initial value>\n");
    printf("example : ./lfsr 5 000...010\n");
    printf("\n");
    printf("1: How many bits(<= 2^31-1 bits) you want to ganerate.\n");
    printf("2: You need to input initial values(<= 128-bits) as binary string.\n");
}

bool checkInvalidInput(int argc, char *input[]) {
    if(argc != 3) {
        printf("[Error] Invalid number of input arguments.\n\n");
        return true;
    }
    
    for(int i=0; i<strlen(input[1]); i++) {
        if(!isdigit(input[1][i])) {
            printf("[Error] input:1 is not digit.\n\n");
            return true;
        }
    }

    int test = atoi(input[1]);
    if(test < 0) {
        printf("[Error] input:1 is not positive integer.\n\n");
        return true;
    }
    
    if (strlen(input[2]) > 128) {
        printf("[Error] length of input:2 is bigger than 128.\n\n");
        return true;
    }

    for (int i = 0; i < strlen(input[2]); i++) {
        if (input[2][i] != '0' && input[2][i] != '1') {
            printf("[Error] input:2 is not binary string.\n\n");
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    if (checkInvalidInput(argc, argv)) {
        usage();
        return -1;
    }

    int numGenerating = atoi(argv[1]);
    
    char *inputInitialValue = argv[2];
    int inputLen = strlen(inputInitialValue);

    bool initialValue[128] = {};
    for (int i = 0; i < strlen(inputInitialValue); i++) {
        initialValue[i] = (inputInitialValue[inputLen - i - 1] - '0');
    }

    

    return 0;
}