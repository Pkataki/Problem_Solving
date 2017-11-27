#include <cstdio>
#include <algorithm>

using namespace std;

int T, n, m;
long long c[50][50];

int main() {

	freopen("popcorn.in", "r", stdin);

	for (int i = 0; i <= 20; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &n, &m);
		printf("%lld\n", c[n][m]);
	}

	//freopen("out.txt", "w", stdout);

	return 0;

}