#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100100;

int T, n, d[N], dis[N];
queue <int> q;
vector <int> g[N];

int main() {

	freopen("jumping.in", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &d[i]);
			if (i - d[i] >= 0) {
				g[i - d[i]].push_back(i);
			}
			if (i + d[i] < n) {
				g[i + d[i]].push_back(i);
			}
			dis[i] = -1;
		}
		dis[n - 1] = 0;
		q.push(n - 1);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < g[now].size(); i++) {
				int nxt = g[now][i];
				if (dis[nxt] == -1) {
					dis[nxt] = dis[now] + 1;
					q.push(nxt);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			printf("%d\n", dis[i]);
		}
		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
 	}

	return 0;

}
