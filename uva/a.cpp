#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 106;

int n,k;
int x[MAX_N],y[MAX_N],type[MAX_N];
vector<int> edg[MAX_N];
int match[MAX_N];
int used[MAX_N];

bool dfs(int id) {
    used[id] = true;
    int len=edg[id].size();
    for (int i=0;len>i;i++) {
        int u=edg[id][i];
        int w=match[u];
        if (w < 0 || !used[w] && dfs(w)) {
            match[id] = u;
            match[u] = id;
            return true;
        }
    }
    return false;
}

int matching() {
    int ret=0;
    memset(match,-1,sizeof(match));
    for (int i=1;n>=i;i++) {
        if (match[i] < 0) {
            memset(used,0,sizeof(used));
            if (dfs(i)) {
                ret++;
            }
        }
    }
    return ret;
}

bool check(int id) {
    for (int i=0;n>=i;i++) {
        edg[i].clear();
    }
    for (int i=1;n>=i;i++) {
        for (int j=i+1;n>=j;j++) {
            if (type[i]+type[j]==0 && (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) <= id*id) {
                cout << i << ' ' << j << ' ' << (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) << endl;
                edg[i].push_back(j);
                edg[j].push_back(i);
            }
        }
    }
    int ret=matching();
    //cout << ret << '\n';
    return ret>=k;
}

int main () {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&k);
        int cnt=0;
        for (int i=1;n>=i;i++) {
            char s[10];
            scanf("%d %d %s",&x[i],&y[i],s);
            if (!strcmp(s,"blue")) type[i] = 1;
            else type[i]=-1,cnt++;
        }
        if (min(cnt,n-cnt) < k) {
            puts("Impossible");
            continue;
        }
        int L=0,R=100006;
        while (R-L!=1) {

            int mid=(L+R)>>1;
            cout << mid << '\n';
            if (check(mid)) R=mid;
            else L=mid;
        }
        printf("%d\n",R);
    }
}
