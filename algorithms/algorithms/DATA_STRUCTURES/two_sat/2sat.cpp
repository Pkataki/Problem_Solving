#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > adjList;
vector<int> dfs_num, dfs_low, SCC, stack;
vector<bool> visited;
bool mark[100005];
int SCCCounter, nodeCounter;
int N;
bool bad_luck;
void TarjanSCC(int u)
{
	if(mark[u])
		return;
    dfs_num[u] = dfs_low[u] = nodeCounter++;
    stack.push_back(u);
    visited[u] = true;

    for (int v : adjList[u])
    {
        if (dfs_num[v] == -1)
            TarjanSCC(v);
        if (bad_luck)
            return;
        if (visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u])
    {

        while (true)
        {
            int v = stack.back();
            stack.pop_back();
            visited[v] = false;
 			cout << v << ' ';
            SCC[v] = SCCCounter;
            if (SCC[v] == SCC[v ^ 1])
            {
            //	cout << v << ' ' << (v ^ 1) << endl ;
                bad_luck = true;
                return;
            }
            //mark[v ^ 1] = false;
            if (u == v)
                break;
        }
        cout << endl;
        SCCCounter++;
    }
    mark[u] = true;
    mark[u ^ 1] = false;
}

int main(){
    int T;
 

        int M;
        scanf("%d %d", &N, &M);
       
        
        adjList.assign(4*N, vector<int>());
        for(int i = 0; i < N; i++)
        {
        	int b1 = 2*i;
        	int b2 = 2*i+1;
        	b1 <<= 1;
        	b2 <<= 1;
        	adjList[b1].push_back(b2 ^ 1);
    		adjList[b1 ^ 1].push_back(b2);

    		adjList[b2].push_back(b2 ^ 1);
    		adjList[b2 ^ 1].push_back(b1);
        }
        for(int i = 0; i < 4*N; i++)
        {
        	cout << i << ": ";
        	for(int j = 0; j < adjList[i].size(); j++)
        		cout << ' ' << adjList[i][j];
        	cout << endl;
        }
        /*
        while (M--)
        {
            int b1, b2;
            char c1,c2;
            scanf("%d%c %d%c", &b1,&c1, &b2,&c2);
            int add1 = (c1 == 'h');
            int add2 = (c2 == 'h');
            b1 = 2*b1+add1;
        	b2 = 2*b2+add2;
        	b1 <<= 1;
        	b2 <<= 1;
        	adjList[b1].push_back(b2 ^ 1);
    		adjList[b2].push_back(b1 ^ 1);
    		adjList[b1 ^ 1].push_back(b2);
    		adjList[b2 ^ 1].push_back(b1);

        }*/

        dfs_num.assign(4*N, -1);
        dfs_low.assign(4*N, 0);
        SCC.assign(4*N, -1);
        SCCCounter = nodeCounter = 0;
        bad_luck = false;
        stack.clear();
        visited.assign(4*N, false);

        for (int i = 0; !bad_luck && i < N; i++)
			if (dfs_num[i] == -1)
				TarjanSCC(i);

        
        if (bad_luck)
            printf("bad luck\n");
       	for(int i = 1 ; i < 2*N ; i += 2)
       	{
            printf("%d",i/2);    
            if(mark[2*i+1]) 
				printf("w ");    
            else 
			    printf("h ");    
            
       	}
       	printf("%d",N);    
        if(mark[2*(N-1)+1]) printf("w\n");    
        else printf("h\n");
        
}
