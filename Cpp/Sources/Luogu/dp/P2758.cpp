#include <array>
#include <iostream>
#include <cstring>
using namespace std;

char A[2004], B[2004];
int N, M, i, j, cost;
array<array<int, 2004>, 2004> dp;

int main (int argc, char *argv[]) {
	scanf("%s", A);
	scanf("%s", B);
	M = strlen(A), N = strlen(B);
	if (!strcmp(A, B)) {
		printf("0");
		return 0;
	}
	for (i = 0; i <= M; ++i) {
		dp[i][0] = i;
	}
	for (j = 0; j <= N; ++j) {
		dp[0][j] = j;
	}
	for (i = 1; i <= M; ++i) {
		for (j = 1; j <= N; ++j) {
			cost = A[i-1] != B[j-1];
			dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + cost);
		}
	}
	printf("%d", dp[M][N]);
	return 0;
}
