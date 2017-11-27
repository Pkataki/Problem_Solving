#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int N;
struct elem {
    int val, pos;
    bool operator< (elem b) const {
        return val<b.val;
    }
};
int* tree[4*MAXN+10];
elem temp[MAXN], arr[MAXN], sorted[MAXN];
int* merge(int e, int d) {
    int* num_left = (int*) malloc(sizeof(int) * (d - e + 1));
    int left = e, right = (e+d)/2+1;
    int i = 0, cnt = 0;
    while (left <= (e+d)/2 && right <= d) {
        if (arr[left].pos <= arr[right].pos) {
            num_left[i] = ++cnt;
            temp[i] = arr[left++];
        }
        else {
            num_left[i] = cnt;
            temp[i] = arr[right++];
        }
        i++;
    }
    while (left <= (e+d)/2) {
        num_left[i] = ++cnt;
        temp[i] = arr[left++];
        i++;
    }
    while (right <= d) {
        num_left[i] = cnt;
        temp[i] = arr[right++];
        i++;
    }
    for (int j = 0; j < (d-e+1); j++) {
        arr[e+j]=temp[j];
    }   
    return num_left;        
}
void create_tree (int i=1, int e=1, int d=N) {
	if (e == d) return;
	else {
		create_tree(2*i, e, (e+d)/2);
		create_tree(2*i+1, (e+d)/2 + 1, d);
		tree[i] = merge(e-1, d-1);
	}
}
int query(int p, int q, int k, int i=1, int st=1, int end=N) {  
    if (st == end) return sorted[st-1].val;
    int left = (p!=1 ? tree[i][p-2] : 0);
    int right = tree[i][q-1];
    int diff = right - left;
    if (diff >= k) 
        return query(left+1,right,k,2*i,st,st+(end-st)/2);
    else 
        return query(p-left,q-right,k-diff,2*i+1,st+(end-st)/2+1,end);
}
map<int,vector<int> > mapa;
int main() 
{
	scanf("%d",&N);
	int q;
    scanf("%d",&q);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &sorted[i].val);
		mapa[sorted[i].val].push_back(i);
		sorted[i].pos = i;
	}
    sort(sorted, sorted+N);
    memcpy(arr,sorted,sizeof(sorted));
    create_tree();
  
    while(q--)
    {
    	int k,i,l;
    	scanf("%d %d %d",&k,&i,&l);
    	int val = query(1,i+1,k);
		if(mapa[val].size() < l)
			printf("-1\n");
		else
    		printf("%d\n",mapa[val][l-1]);
	}
}
