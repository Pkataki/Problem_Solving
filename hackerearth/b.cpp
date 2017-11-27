#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 310;
const double INF = 1e16;

struct rect {
	int x1;
	int y1;
	int x2;
	int y2;

	rect() {}

	rect(int _x1, int _y1, int _x2, int _y2) {
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
	}

	friend bool operator < (rect a, rect b) {
		if (a.x2 == b.x2)
			return a.x1 < b.x1;
		else
			return a.x2 < b.x2;
	}
} rec[N];

int T, n, L, U, h[N], w[N], d[N], k[N];
double dij[N], g[N][N];
vector < pair <int, int> > v[N];

double cal(double x1, double y1, double x2, double y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}

int main() {

	freopen("street.in", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d", &n, &L, &U);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d %d", &h[i], &w[i], &d[i], &k[i]);
			if (k[i] == 0) {
				rec[i] = rect(d[i], 0, d[i] + h[i], w[i]);
			} else {
				rec[i] = rect(d[i], U - w[i], d[i] + h[i], U);
			}
		}
		for (int i = 0; i < n; i++) {
			v[i].clear();
			v[i].push_back(make_pair(rec[i].x1, rec[i].y1));
			v[i].push_back(make_pair(rec[i].x1, rec[i].y2));
			v[i].push_back(make_pair(rec[i].x2, rec[i].y1));
			v[i].push_back(make_pair(rec[i].x2, rec[i].y2));
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				double mdist = INF;
				for (int ii = 0; ii < v[i].size(); ii++) {
					for (int jj = 0; jj < v[j].size(); jj++) {
						double tmp = cal(v[i][ii].first, v[i][ii].second, v[j][jj].first, v[j][jj].second);
						mdist = min(mdist, tmp);
					}
				}
				if (!(rec[i].x1 > rec[j].x2 || rec[j].x1 > rec[i].x2)) {
					mdist = min(mdist, 0.0 + abs(rec[i].y1 - rec[j].y2));
					mdist = min(mdist, 0.0 + abs(rec[i].y2 - rec[j].y1));
				}
				if (!(rec[i].y1 > rec[j].y2 || rec[j].y1 > rec[i].y2)) {
					mdist = min(mdist, 0.0 + abs(rec[i].x1 - rec[j].x2));
					mdist = min(mdist, 0.0 + abs(rec[i].x2 - rec[j].x1));
				}
				g[i][j] = mdist;
			}
		}
		set < pair <double, int> > ss;
		for (int i = 0; i < n; i++) {
			dij[i] = rec[i].x1;
			ss.insert(make_pair(dij[i], i));
		}
		while (!ss.empty()) {
			pair <double, int> now = *ss.begin();
			ss.erase(ss.begin());
			for (int i = 0; i < n; i++) {
				if (dij[i] > now.first + g[now.second][i]) {
					if (ss.count(make_pair(dij[i], i)) != 0) {
						ss.erase(make_pair(dij[i], i));
					}
					dij[i] = now.first + g[now.second][i];
					ss.insert(make_pair(dij[i], i));
				}
			}
		}
		double ans = L;
		for (int i = 0; i < n; i++) {
			ans = min(ans, dij[i] + L - rec[i].x2);
		}
		printf("%.6f\n", ans);
	}

	return 0;

}
