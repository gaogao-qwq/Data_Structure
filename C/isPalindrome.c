#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *s) {
    int len = strlen(s);
    char str[200001] = {};
    for (int i = 0, j = 0; i < len; ++i) {
        if((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)) {
            str[j] = s[i];
            j++;
        }
        if(s[i] >= 65 && s[i] <= 90) {
            str[j] = s[i] + 32;
            j++;
        }
    }
    len = strlen(str);
    int mid = len / 2;
    for (int i = 0, j = len - 1; i < mid; ++i, --j) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    char str[] = {"abb"};
    printf("%d", isPalindrome(str));
    return 0;
}