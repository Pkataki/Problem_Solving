#include<bits/stdc++.h>

using namespace std;

const int maxn = 100005, maxm = 100005;

vector<int> tree[maxn]; 
vector<int> graph[maxn];
int U[maxm],V[maxm];  
bool isbridge[maxm]; 
int visited[maxn];
int times[maxn],T; 
int cmpno;
queue<int> q[maxn];
 
int adj(int u,int e){
    return U[e] == u ? V[e] : U[e];
}
int tarjan(int u,int edge)   
{
    visited[u] = 1;
    times[u] = T++;
    int disc = times[u];
    for(int i = 0; i < graph[u].size(); i++)
    {
        int e = graph[u][i];
        int w = adj(u,e);
        if(!visited[w])
            disc = min(disc,tarjan(w,e));
        else if(e!=edge)
            disc = min(disc,times[w]);
    }
    if(disc == times[u] && edge!=-1)
        isbridge[edge]=true;
    return disc;
}
 
void bridged_tree(int v) 
{
    int currcmp = cmpno;   
    q[currcmp].push(v);    
    visited[v] = 1;
    while(!q[currcmp].empty())    
    {
        int u = q[currcmp].front();    
        q[currcmp].pop();    
        for(int i = 0;i < graph[u].size(); i++)
        {
            int e = graph[u][i];
            int w = adj(u,e);
            if(visited[w])
            	continue;
            if(isbridge[e])
            {
                cmpno++;
                tree[currcmp].push_back(cmpno);
                tree[cmpno].push_back(currcmp);
               	bridged_tree(w);
            }
            else 
            {
                q[currcmp].push(w);
                visited[w] = 1;
            }
        }
    }
}

void clear()
{
	for(int i = 0; i < maxn; i++)
	{
		tree[i].clear();
		graph[i].clear();
		while(q[i].size())
		{
			q[i].pop();
		}
	}
	T = 0;
	cmpno = 0;
	memset(isbridge,0,sizeof(isbridge));
	memset(times,0,sizeof(times));
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= m ; i++)
	{
		scanf("%d %d",&U[i], &V[i]);
		graph[U[i]].push_back(i);
		graph[V[i]].push_back(i);
	}

	tarjan(1,-1);
	memset(visited,0,sizeof(visited));
	bridged_tree(1);
	
	return 0;
}
