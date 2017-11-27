
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
int a,b;
vector<int> graph[MAX], graph1[MAX];
bool vis[MAX];
int dp[MAX];
int n;
void Build()
{
    int node;
 
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        if(vis[top])continue;
        vis[top]=1;
        for (int i=0; i<graph[top].size(); i++)
        {
            node =graph[top][i];
            if(!vis[node])
            {
                q.push(node);
                graph1[top].push_back(node);
            }
        }
    }
}
int solve(int node)
{
    if(graph1[node].size()==0)
        return 0;
    if(dp[node] != -1)
    	return dp[node];
    int ans=0;
  
    for (int i=0; i<graph1[node].size(); i++)
        ans+=solve(graph1[node][i]);
    for (int i=0; i<graph1[node].size(); i++)
    {
        if(!vis[graph1[node][i]])
        {
            vis[node]=1;
            break;
        }
    }
    if(vis[node])ans++;

    return dp[node]=ans ;
}
int main()
{

    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    
    for (int i=0; i<n-1; i++)
    {
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    Build();
    fill(&vis[0],&vis[n+1],false);


    printf("%d\n",solve(1));


    return 0;
}