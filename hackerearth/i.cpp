#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 500000;

int T, n, m, x, y, r, fen[N];
vector <int> c;
vector < pair <int, int> > v;

void add(int pos, int by) {
	while (pos < N) {
		fen[pos] += by;
		pos |= (pos + 1);
	}
}

int ask(int pos) {
	int ret = 0;
	while (pos >= 0) {
		ret += fen[pos];
		pos = (pos & (pos + 1)) - 1;
	}
	return ret;
}

int main() {

	freopen("walk.in", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &r);
			if (y + r > m || y - r < -m) {
				continue;
			}
			if (r <= m) {
				v.push_back(make_pair(x - r, x + r));
			}
		}
		memset(fen, 0, sizeof fen);
		for (int i = 0; i < v.size(); i++) {
			c.push_back(v[i].first);
			c.push_back(v[i].second);
			c.push_back(v[i].second + 1);
		}
		int res = 0;
		sort(c.begin(), c.end());
		sort(v.begin(), v.end());
		int l = unique(c.begin(), c.end()) - c.begin();
		vector < pair <int, int> > u = v;
		for (int i = 0; i < u.size(); i++) {
			swap(u[i].first, u[i].second);
		}
		sort(u.begin(), u.end());
		c.resize(l);
		c.push_back(2000000000);
		for (int i = 0, j = 0, k = 0; i < l; i++) {
			long long right = c[i] + 2LL * m;
			while (j < v.size() && v[j].first >= c[i]) {
				int id = lower_bound(c.begin(), c.end(), v[j].second) - c.begin();
				add(id, 1);
				j++;
			}
			while (k < u.size() && u[k].first < c[i]) {
				int id = lower_bound(c.begin(), c.end(), u[k].first) - c.begin();
				add(id, -1);
				k++;
			}
			int id = lower_bound(c.begin(), c.end(), right + 1) - c.begin();
			res = max(res, ask(id - 1));
		}
		printf("%d\n", res);
		v.clear();
		c.clear();
	}

	return 0;

}
