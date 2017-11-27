#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 3000010;

int T, n, u, v, d, x[N], fen[N], from[N], to[N], res[N];
long long dis[N];
vector < pair <int, int> > g[N];
pair < long long, pair <int, int> > ev[N];

bool cmp(pair < long long, pair <int, int> > a, pair < long long, pair <int, int> > b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}
	if (a.second.first != b.second.first) {
		return a.second.first < b.second.first;
	}
	return a.second.second < b.second.second;
}

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

void dfs(int now, int par, int &cnt) {
	from[now] = cnt++;
	for (int i = 0; i < g[now].size(); i++) {
		int nxt = g[now][i].first;
		if (nxt != par) {
			dis[nxt] = dis[now] + g[now][i].second;
			dfs(nxt, now, cnt);
		}
	}
	to[now] = cnt - 1;
}

int main() {

	freopen("car.in", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int cnt = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x[i]);
			dis[i] = -1;
		}
		for (int i = 1; i < n; i++) {
			scanf("%d %d %d", &u, &v, &d);
			u--;
			v--;
			g[u].push_back(make_pair(v, d));
			g[v].push_back(make_pair(u, d));
		}
		dis[0] = 0;
		dfs(0, -1, cnt);
		for (int i = 0; i < n; i++) {
			ev[i] = make_pair(dis[i], make_pair(1, i));
			ev[i + n] = make_pair(dis[i] - x[i], make_pair(-1, i));
		}
		sort(ev, ev + (2 * n), cmp);
		memset(fen, 0, sizeof fen);
		for (int i = 0; i < 2 * n; i++) {
			int id = ev[i].second.second;
			int op = ev[i].second.first;
			if (op == -1) {
				add(from[id], 1);
			} else {
				res[id] = ask(to[id]) - ask(from[id] - 1) - 1;
			}
		}
		printf("%d", res[0]);
		for (int i = 1; i < n; i++) {
			printf(" %d", res[i]);
		}
		puts("");
		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
	}

	return 0;

}