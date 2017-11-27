
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const double INF = 1e50;

//funcao de comparacao
int cmp(double a, double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// representation of undirected edge (u, v) having weight 'weight'
struct Edge {
    int u, v;
    int a,b;
};

// Union-find data structure
class UF    {
    int *id, cnt, *sz;
public:
	// Create an empty union find data structure with N isolated sets.
    UF(int N)   {
        cnt = N;
	id = new int[N];
	sz = new int[N];
        for(int i=0; i<N; i++)	{
            id[i] = i;
  	    sz[i] = 1;
	}
    }
    ~UF()	{
	delete [] id;
	delete [] sz;
    }
	// Return the id of component corresponding to object p.
    int find(int p)	{
        int root = p;
        while (root != id[root])
            root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
	// Replace sets containing x and y with their union.
    void merge(int x, int y)	{
        int i = find(x);
        int j = find(y);
        if (i == j) return;
		
		// make smaller root point to larger one
        if   (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
        else                 { id[j] = i; sz[i] += sz[j]; }
        cnt--;
    }
	// Are objects x and y in the same set?
    bool connected(int x, int y)    {
        return find(x) == find(y);
    }
	// Return the number of disjoint sets.
    int count() {
        return cnt;
    }
};

// comparator function for sorting edges in ascending order by weight
bool comp(Edge *e1, Edge *e2)   {
    if(e1->b < e2->b)
    {
    	if(!(e1->a > e2->a))
    		return 1;
    	return 1;
    }
   	else if(e1->b == e2->b)
   		return (e1->a > e2->a);

   	return 0;
}

int main()  {
    int V, E, i, N, u, v;
    Edge **edges;

    // Assuming vertices are labeled 0...V-1
    //freopen("input1.txt", "r", stdin);
   
    scanf("%d %d", &V, &E); // Enter the number of vertices and edges
    edges = new Edge*[E];
    for(i=0; i<E; i++)  {   // Enter E undirected edges (u, v, weight)
        edges[i] = new Edge;
         int f,g,r,t;
        scanf("%d %d %d %d", &f, &g,&r,&t);
        if(f == g)
        		continue;
        edges[i]->u = f;
        edges[i]->v = g;
        edges[i]->a = r;
        edges[i]->b = t;
    }
    sort(edges, edges + E, comp);

    UF uf(V);
   
    int costa = 0;
    int costb = 0;
    for(N=i=0; i<E && N<V-1; i++)
    {

        u = edges[i]->u;
        v = edges[i]->v;
        cout << u  << " "<< v << " "<< edges[i]->a << " " << edges[i]->b << '\n';
        if(!uf.connected(u, v))
        {
            uf.merge(u, v);
            costa += edges[i]->a;
            costb += edges[i]->b;
        }
    }
    int aux = gcd(costa,costb);
    if(int(costa/aux) == int(costb/aux))
    	puts("1");
    else
    {
    	printf("%d/%d\n",int(costa/aux), int(costb/aux));
    }

    return 0;
}
