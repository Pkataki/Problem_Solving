#define MAXN 40001

int pa[MAXN], rk[MAXN], tCnt[MAXN];
//pai, rank, numero de nos na subarvore(se este no e o raiz)

void init(int n){
    for(int i = 0; i < n; i++){
    	pa[i] = i;
    	rk[i] = 0;
    	tCnt[i] = 1;
    }
}

int find(int x){
    int a = x;
    while(pa[a] != a) a = pa[a];
    int b = x, c;
    while(pa[b] != a){
    	c = pa[b];
    	pa[b] = a;
    	b = c;
    }
    
    return a;
}

void uf(int x, int y){
    int ax = find(x);
    int ay = find(y);
    
    if(ax == ay) return;
    if(rk[ay] > rk[ax]) swap(ax, ay);
    if(rk[ax] == rk[ay]) rk[ax]++;
    pa[ay] = ax;
    tCnt[ax] += tCnt[ay];
}
