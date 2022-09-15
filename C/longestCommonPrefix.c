#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    for(int j = 0; strs[0][j] != '\0'; j++) {
        for(int i = 0; i < strsSize - 1; i++) {
            if( strs[i][j] != strs[i + 1][j] ) {
                strs[0][j] = '\0';
                return strs[0];
            }
        }
    }
    return strs[0]; 
}

int main(void) {
    char *strs[] = {"flower", "flight", "flow"};
    printf(strs[0]);
    char *ret = longestCommonPrefix(strs, 3);
    printf("%s", ret);
    return 0;
}