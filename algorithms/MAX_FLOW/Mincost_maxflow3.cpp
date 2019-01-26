#include<bits/stdc++.h>
using namespace std;
const int maxn = 85;

const int INF=int(1e9)+7;
const int maxd=maxn*maxn;
const int maxe=int(1e5)+10;
int tot=0;
int head[maxd];
int S,T;

struct Edge {
    int from,to,cap,cost,next;
    Edge() {}
    Edge(int x,int y,int a,int b,int c):from(x),to(y),cap(a),cost(b),next(c) {}
}eage[maxe*2];

void add_edge(int x,int y,int a,int b) {
    eage[tot]=Edge(x,y,a,b,head[x]), head[x]=tot++;
    eage[tot]=Edge(y,x,0,-b,head[y]), head[y]=tot++;
    return;
}

bool used[maxd],vis[maxd];
int dis[maxd];
queue<int> que;
int ans=0;

bool spfa()
{
    for(int i = 0;i < maxd;i++) 
        used[i]=false,dis[i]=INF,vis[i]=false;
    while(que.size()) 
        que.pop();

    que.push(S);
    used[S]=true;
    dis[S]=0;

    while(que.size())
    {
        int u=que.front(); 
        que.pop();
        used[u]=false;
        for(int i=head[u];~i;i=eage[i].next) if(eage[i].cap && dis[eage[i].to] > dis[u]+ e age[i].cost) {
            int v=eage[i].to;
            dis[v] = dis[u] + eage[i].cost;
            if(!used[v]) {
                used[v]=true;
                que.push(v);
            }
        }
    }
    return (dis[T]<INF);
}

int dfs(int u,int flow)
{
    if(u == T)
    {
        ans += dis[u]*flow;
        return flow;
    }
    vis[u] = true;
    int ret = 0;
    for(int i=head[u];~i;i=eage[i].next)
    { 
        if(!vis[eage[i].to] && eage[i].cap && dis[eage[i].to]==dis[u]+eage[i].cost)
        {
            int v=eage[i].to;
            
            int newf=dfs(v,min(flow,eage[i].cap));
            
            eage[i].cap-=newf;
            
            eage[i^1].cap+=newf;
            
            ret+=newf;
            
            flow-=newf;
            if(!flow)
                break;
        }
    }
    if(!ret) dis[u]=-1;
    return ret;
}

void init(int s, int t)
{

}

int MCMF() {
    ans=0;
    while(spfa()) dfs(S,INF);
    return ans;
}

int main()
{
   
    S = n*m+2;
    T = n*m+3;
    
    memset(head,-1,sizeof head);
  
    printf("%d\n",MCMF());
    return 0;

}