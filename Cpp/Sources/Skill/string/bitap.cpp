#include <stdio.h>
#include <cstring>
#include <climits>

const char *bitap_search(const char *text, const char *pattern) {
	int m = strlen(pattern), i;
	size_t R = ~1, pattern_mask[CHAR_MAX+1];

	if (pattern[0] == '\0') return text;
	if (m > 31) return "The pattern is too long!";

	for (i = 0; i <= CHAR_MAX; ++i) {
		pattern_mask[i] = ~0;
	}
	for (i = 0; i < m; ++i) {
		pattern_mask[pattern[i]] &= ~(1UL << i);
	}

	for (i = 0; text[i] != '\0'; ++i) {
		R |= pattern_mask[text[i]];
		R <<= 1;
		if (0 == (R & (1UL << m)))
			return (text + i - m) + 1;
	}
	return NULL;
}

int main(const int argc, const char *argv[]) {
	if (argc != 3) {
		printf("Must take in 2 arguments\n");
		return 0;
	}
	const char *res = bitap_search(argv[1], argv[2]);
	if (res == NULL) {
		printf("Not found\n");
		return 0;
	}
	printf("Founded: %s\n", res);
	return 0;
}
