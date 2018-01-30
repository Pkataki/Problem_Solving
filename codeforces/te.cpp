#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <cassert>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define FOR(AA,BB,CC) for(int AA=(BB); AA<(CC); ++AA)
#define FC(AA,BB) for(__typeof((AA).begin()) BB=(AA).begin(); BB!=(AA).end(); ++BB)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back
#define MP make_pair

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

const int MAXN = 1000;
char c[MAXN + 10];

bool prime(int k) {
    if (k == 1) {
        return false;
    }
    for (int i = 2; i * i <= k; ++i) {
        if (k % i == 0) {
            return false;
        }
    }
    return true;
}

int cnt[256];

int main(void) {
    scanf("%s", c);
    int n = strlen(c), r = n - 1;
    REP (i, n) {
        ++cnt[c[i]];
    }
    vector<pair<int, char> > z;
    for (int i = 'a'; i <= 'z'; ++i) {
        if (cnt[i] > 0) {
            z.PB(MP(cnt[i], i));
        }
    }
    sort(ALL(z));
    for (int i = 2; i <= n; ++i) {
        if (prime(i) && 2 * i > n) {
            --r;
        }
    }
    if (r > z.back().first) {
        puts("NO");
    } else {
        vector<char> w;
        REP (i, SZ(z) - 1) {
            REP (j, z[i].first) {
                w.PB(z[i].second);
            }
        }
        REP (j, z.back().first - r) {
            w.PB(z.back().second);
        }
        puts("YES");
        for (int i = 1; i <= n; ++i) {
            if (i == 1 || (prime(i) && 2 * i > n)) {
                putchar(w.back());
                w.pop_back();
            } else {
                putchar(z.back().second);
            }
        }
        puts("");
    }
    return 0;
}