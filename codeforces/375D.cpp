#include <bits/stdc++.h>
using namespace std;

#define N 100005
const int MAXN = 100010;
int cor[N], ans[N], ans1 = 0;
int BLOCK;
struct node {
	int no, k, i;
}q[N];
vector<int>graph[N];
int in[N],out[N];
int v[N];
int cnt = 1;
int c1[MAXN];
void dfs(int u, int pai)
{
	v[cnt] = u;
	in[u] = cnt;
	c1[cnt] = cor[u];
	for(int i = 0; i < graph[u].size(); i++)
	{
		int v = graph[u][i];
		if(v == pai)
			continue;
		cnt++;
		dfs(v,u);
	}
	out[u] = cnt;
}

int bit[MAXN+5];
int cont[MAXN];


bool cmp(node x, node y) {
	if(in[x.no]/BLOCK != in[y.no]/BLOCK) {
		return in[x.no]/BLOCK < in[y.no]/BLOCK;
	}
	return out[x.no] < out[y.no];
}
int qt[MAXN];
void add(int pos)
{
	cont[c1[pos]]++;
	qt[cont[c1[pos]]]++;
}

void remove(int pos)
{
	qt[cont[c1[pos]]]--;
	cont[c1[pos]]--;
	
}

int main() {
	int n;
	
	int m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &cor[i]);
	}
	for(int i = 1; i < n; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1,1);
	BLOCK = sqrt(n);
	for(int i=0; i<m; i++)
	{
		scanf("%d %d", &q[i].no, &q[i].k);
		q[i].i = i;
	}

	sort(q, q + m, cmp);

	int currentL = 0, currentR = 0;

   
 
	for(int i=0; i<m; i++)
	{
		//cout << i << endl;
		int L = in[q[i].no]; 
		int R = out[q[i].no];
		while(currentL < L) {
			remove(currentL);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}
		
		while(currentR <= R) {
			add(currentR);
			currentR++;
		}
		
		while(currentR > R+1) {
			remove(currentR-1);
			currentR--;
		}
		
		//cout <<query(1000-1) << endl;
		//cout << q[i].no << ' ' << q[i].i << ' ' << q[i].k << endl;
		ans[q[i].i] = qt[q[i].k];
	}

	for(int i=0; i<m; i++)
		printf("%d\n", ans[i]);
}