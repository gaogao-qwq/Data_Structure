#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool checkIfPangram(char *sentence) {
    int hash[26] = {}, len = strlen(sentence);
    for(int i = 0; i < len; ++i) {
        ++hash[(sentence[i] - 97)];
    }
    for(int i = 0; i < 26; ++i) {
        if(hash[i] < 1) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    char str[] = {"thequickbrownfoxjumpsoverthelazydog"};
    bool ret = checkIfPangram(str);
    return 0;
}