/**
 * This program is for 1st problem of CryptContest 2024.
 * m = 128 (number of flip-flop)
 * feedback coefficients = (0, 1, 2, 7, 128)
 */

#include <stdio.h>
#include <string.h>

void usage() {
    printf("usage : ./lfsr <initial value>\n");
    printf("example : ./lfsr 0000...011010\n");
    printf("You need to input initial values(<= 128-bits) as binary string.\n");
}

bool checkInvalidInput(char *input) {
    if (strlen(input) > 128) {
        return true;
    }

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != '0' && input[i] != '1') {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    if (argc != 2 || checkInvalidInput(argv[1])) {
        usage();
        return -1;
    }

    char *input = argv[1];
    int inputLen = strlen(input);

    bool initial_value[128] = {};
    for (int i = 0; i < strlen(input); i++) {
        initial_value[i] = (input[inputLen - i - 1] - '1');
    }

    return 0;
}