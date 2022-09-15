#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkZeroOnes(char *s) {
    int max0 = 0, max1 = 0, count = 0, len = strlen(s);
    char prev = '#';
    for(int i = 0; i <= len; ++i) {
        if(s[i] == prev) {
            ++count;
        } else {
            if(prev == '1') {
                max1 = (max1 < count) ? count: max1;
            } else if(prev == '0') {
                max0 = (max0 < count) ? count: max0;
            }
            count = 1;
        }
        prev = s[i];
    }
    if(max1 > max0) {
        return true;
    } else {
        return false;
    }
}

int main (void) {
    char str[] = {"111000"};
    printf("%d", checkZeroOnes(str));
    return 0;
}
