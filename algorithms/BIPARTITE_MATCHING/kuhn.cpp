
const int maxn = 500;
bool vis[maxn];
vector<int>graph[maxn];
 
int match[maxn];
 
bool dfs(int u)
{
  for(int i = 0 ; i < graph[u].size(); i++)
  {
    int v = graph[u][i];
    if(vis[v] == 0)
    {
      vis[v] = 1;
      if(match[v] == -1 || dfs(match[v]))
      {
        match[v] = u;
        return true;
      }
    }
  }
  return false;
}
 
int matching(int n)
{
  int ans = 0;
  memset(match,-1,sizeof(match));
  for(int i = 0; i < n; i++)
  {
    memset(vis,0,sizeof(vis));
    ans += dfs(i);
  }
  return ans;
} 
