#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ",.!?"
// NATO['A'] == "Alfa", etc
const char *NATO[0xff];

char *to_nato(const char *words) {
    char *ans;
    size_t i, j, len;

    len = strlen(words);
    ans = calloc(len * 8, sizeof(char));
    j = 0;
    for (i = 0; i < len; ++i) {
		if (words[i] == ',' || words[i] == '.' || words[i] == '!' || words[i] == '?') {
			ans[j++] = words[i];
			if (i == len - 1) break;
			ans[j++] = ' ';
			continue;
		}
		if (isalpha(words[i])) {
			strcat(ans, NATO[(unsigned char)toupper(words[i])]);
			j += strlen(NATO[(unsigned char)toupper(words[i])]);
			if (i == len - 1) break;
			ans[j++] = ' ';
		}
    }
    return ans;
}

int main(void) {
    NATO['A'] = "Alfa";
    NATO['B'] = "Bravo";
    NATO['C'] = "Charlie";
    NATO['D'] = "Delta";
    NATO['E'] = "Echo";
    NATO['F'] = "Foxtrot";
    printf("%s\n", to_nato("A.B!CD,E?"));
}
