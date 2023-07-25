#include "shell.h"


int _atoi(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++; // Move to the next character after the sign
    }

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return (-2);
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return sign * result;
}

