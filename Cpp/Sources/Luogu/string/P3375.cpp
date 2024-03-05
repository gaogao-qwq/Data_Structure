#include <cstdio>
#include <cstring>
using namespace std;

static char s1[1000004], s2[1000004];
static int next[1000004];
static unsigned int i, j, m, n, pos, cnd;

int main (int argc, char *argv[]) {
	scanf("%s%s", s1, s2);
	m = strlen(s1), n = strlen(s2);
	pos = 1, cnd = 0;
	while (pos < n) {
		if (s2[cnd] == s2[pos]) {
			next[pos] = ++cnd, ++pos;
		} else if (cnd > 0) {
			cnd = next[cnd-1];
		} else {
			next[pos] = 0, cnd = 0, ++pos;
		}
	}
	while (i < m) {
		// printf("i=%d,j=%d\n", i, j);
		if (s1[i] == s2[j]) {
			if (j == n-1) {
				printf("%d\n", i-j+1);
				j = next[j-1];
				continue;
			}
			++i, ++j;
			continue;
		}
		if (j > 0) {
			j = next[j - 1];
			continue;
		}
		++i;
	}
	for (i = 0; i < n; ++i) {
		printf("%d ", next[i]);
	}
	return 0;
}
