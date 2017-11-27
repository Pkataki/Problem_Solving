#include<bits/stdc++.h>
using namespace std;
int res[105][105];
int m,w;
vector <int> parent;
int flow;
void augment ( int v ,int minedge){ if( parent[v] == -1){ flow=  minedge; return ;}
      else{ augment(parent[v] , min(minedge,res[parent[v]][v]) );
          res[parent[v]][v] -= flow;
          res[v][parent[v]] += flow;
       }
}
int ans;
void edmond_karp()
{
	ans = 0;	
	flow = 0;
	while(1)
	{
		queue<int>q;
		parent.assign(2*m+1,-1);
		
		bitset<105>vis;
		q.push(3);
		vis.set(3);
		while(!q.empty())
		{
			int at = q.front();
			q.pop();
			if(at == 2*m)
			{
				break;
			}
			for(int i = 1; i <= 2*m; i++)
			{
				if(!vis.test(i) && res[at][i] > 0)
				{
					vis.set(i);
					parent[i] = at;
					q.push(i);
				}
			}
		}
		
		augment(2*m,(1 << 28));
		if(flow == 0 || flow == (1 << 28))
			break;
		ans += flow;
	}
}
int main()
{
	 while ( scanf("%d %d",&m ,&w))
	 {
    	 if( m == 0 && w == 0)
    		 break ;
       int j,k,c;
       memset ( res , 0, sizeof res);
       for (int i = 0 ; i < m-2 ; i++)
       {
         scanf("%d  %d",&j , &c);
         res[2*j][2*j+1] = c ;
       }

       for (int i = 0 ; i < w ; i++)
       {
         scanf("%d %d %d",&j, &k ,&c);
         res[2*j+1][2*k] = res[2*k+1][2*j] = c;
       }
       edmond_karp();
       printf("%d\n",ans);
    }
	return 0;
}
