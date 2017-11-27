#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

int sg[100];

int bgrundy(int n, int k) {
	for (int i = 0; i <= n; i++) {
		int p = 1;
		set <int> s;
		sg[i] = 0;
		while (p <= i) {
			s.insert(sg[i - p]);
			p *= k;
		}
		while (s.count(sg[i]) != 0) {
			sg[i]++;
		}
	}
	return sg[n];
}

int cal_sg(int n, int k) {
	if (k % 2 == 1) {
		return n % 2;
	} else {
		n %= (k + 1);
		if (n == k) {
			return 2;
		} else {
			return n % 2;
		}
	}
}

int T, m, n, k;

int main() {

	freopen("powers.in", "r", stdin);

	for (int i = 2; i <= 30; i++) {
		//printf("%d %d\n", i, bgrundy(i, 1));
	}

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		long long ans = 0;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &k, &n);
			ans ^= cal_sg(n, k);
		}
		printf("%d\n", ans == 0 ? 2 : 1);
	}

	return 0;

}