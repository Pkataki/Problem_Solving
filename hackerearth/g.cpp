#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000010;
const int MOD = (int) 1e9 + 7;

int T, n, K;
long long f[N], r[N];

long long fpw(long long e, long long k) {
	if (k == 0) {
		return 1LL;
	}
	if (k % 2 == 0) {
		return fpw(e * e % MOD, k / 2);
	} else {
		return fpw(e, k - 1) * e % MOD;
	}
}

long long comb(int n, int k) {
	return f[n] * r[k] % MOD * r[n - k] % MOD;
}

int main() {

	//freopen("galactic.in", "r", stdin);

	f[0] = 1;

	for (int i = 1; i < N; i++) {
		f[i] = f[i - 1] * i % MOD;
	}

	for (int i = 0; i < N; i++) {
		r[i] = fpw(f[i], MOD - 2);
	}

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &n, &K);
		long long res = 0;
		for (int i = 0; i <= n; i++) {
			int j = n - i;
			long long tmp = comb(n, i) * fpw(K, j) % MOD;
			if (i % 2 == 0) {
				res += tmp;
				if (res >= MOD) {
					res -= MOD;
				}
			} else {
				res -= tmp;
				if (res < 0) {
					res += MOD;
				}
			}
		}
		printf("%lld\n", res);
	}

	return 0;

}