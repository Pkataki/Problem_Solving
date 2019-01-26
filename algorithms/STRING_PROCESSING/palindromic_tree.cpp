#include<bits/stdc++.h>
using namespace std;

const int N = 200005;


int q[N];

int n;
int sz;
int last;
int s[N];
//int pos[N];
//int occ[N];
int len[N];
int link[N];
int deg[N];
int to[N][30];

void init() 
{
    n = 0;
    last = 0;
    sz = 2;
    mask[0] = 0;
    mask[1] = 0;
    s[n++] = -1;
    len[0] = 0;
    len[1] = -1;
    link[0] = 1;
    link[1] = 0;
    //memset(mask,0,sizeof(mask));
    memset(to[0], 0, sizeof to[0]);
    memset(to[1], 0, sizeof to[1]);
}

int get_link(int v) {
    while (s[n - len[v] - 2] != s[n - 1]) {
        v = link[v];
    }
    return v;
}

void add_letter(int c, int at) {
    s[n++] = c;
    last = get_link(last);
    
    if (to[last][c] == 0) {
       
        len[sz] = len[last] + 2;
        pos[sz] = (n-1) - len[sz] + 1;
        link[sz] = to[get_link(link[last])][c];
        memset(to[sz], 0, sizeof to[sz]);
        to[last][c] = sz++;
    }
    last = to[last][c];
    mask[last] |= (1 << at);
  
}

int bfs(int val)
{
    //memset(deg,0,sizeof(deg));
    int ans = 0;
    int p = 0;
    for(int i = 1; i < sz; i++)
    {
        deg[link[i]]++;
    }
    for(int i = 1; i < sz; i++)
    {
        if(deg[i] == 0)
            q[++p] = i;
    }
   
    while(p)
    {
        int at = q[p];
        p--;

        if(at <= 0)
            break;
        mask[link[at]] |= mask[at];
        if(mask[at] == val)
            ans = max(ans,len[at]);
        mask[at] = 0;
        if((--deg[link[at]]) == 0)
            q[++p] = link[at];
    }
    return ans;
}



bool readString( int id )
{
    char c = getchar_unlocked();
    while(c == '\n' || c == ' '){
        c = getchar_unlocked();
    
    }
    //cout <<  "**" << int(c)  << endl;
    while( c != EOF && c >= 'a' && c <= 'z'  )
    {
        //cout << c ;
        add_letter(c - 'a',id);
        c = getchar_unlocked();
    }
    //exit(0);
    return c == EOF;
}
 

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        init();
        for(int i = 0; i < n; i++)
        {
            readString(i);
            //cout << endl;
            if(i != n-1)
                add_letter('{' - 'a',i);
        }
        printf("%d\n",bfs((1 << n) - 1));
    }

    return 0;
}