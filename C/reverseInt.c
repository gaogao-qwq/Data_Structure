#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *a, char *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void reverseStr(char *str, int left) {
    for(int i = left, j = 0; i < (left + strlen(str)) / 2; ++i, ++j) {
        swap( &(str[i]), &(str[strlen(str) - 1 - j]) );
    }
}

int reverse(int x){
    int left = 0;
    char str[12] = {};
    sprintf(str, "%d", x);
    if(str[0] == '-') {
        left = 1;
    } else {
        left = 0;
    }
    reverseStr(str, left);
    if(atoll(str) >= -2147483647 && atoll(str) <= 2147483647) {
        return atoi(str);
    }
    return 0;
}

int main(void) {
    int ret = 0;
    int x = 1534236469;
    ret = reverse(x);
    return 0;
}