#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n, f, y, x, h, a[11][11][11], dp[11][11][11];

int main() {

	freopen("commandos.in", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);
		memset(a, 0, sizeof a);
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d %d", &f, &y, &x, &h);
			f = 11 - f;
			a[f][y][x] += h;
		}
		int res = 0;
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				for (int k = 1; k <= 10; k++) {
					dp[i][j][k] += a[i][j][k];
					res = max(res, dp[i][j][k]);
					if (i + 1 <= 10) {
						dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
					}
					if (j + 1 <= 10) {
						dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
					}
					if (k + 1 <= 10) {
						dp[i][j][k + 1] = max(dp[i][j][k + 1], dp[i][j][k]);
					}
				}
			}
		}
		printf("%d\n", res);
	}

	return 0;

}
