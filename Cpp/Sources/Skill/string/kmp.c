#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int *prefix_function(const char *str) {
	size_t n = strlen(str);
	int *pre = (int *)malloc(n * sizeof(int));
	int i = 0, j = 0;
	for (i = 1; i < n; ++i) {
		j = pre[i-1];
		while (j > 0 && str[i] != str[j]) j = pre[j-1];
		if (str[i] == str[j]) ++j;
		pre[i] = j;
	}
	return pre;
}

void find_occurrences(const char *text, const char *pattern) {
	int i, j, m = strlen(text), n = strlen(pattern);
	if (m < n) {
		fprintf(stderr, "Pattern must be shorter than text.");
		exit(1);
	}
	int *pre = prefix_function(pattern);
	while (i < m) {
		if (text[i] == pattern[j]) {
			if (j == n-1) {
				printf("%d\n", i-j+1);
				j = pre[j-1];
				continue;
			}
			++i, ++j;
			continue;
		}
		if (j > 0) {
			j = pre[j - 1];
			continue;
		}
		++i;
	}
}

int main(const int argc, const char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Must take in 2 arguments!");
		return EINVAL;
	}
	const char *text = argv[1], *pattern = argv[2];
	find_occurrences(text, pattern);
	return 0;
}
