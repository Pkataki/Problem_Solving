#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100009
using namespace std;

int d[maxn][30],value[maxn],cnt[maxn],num[maxn],left[maxn],right[maxn];

void RMQ_init(int n)
{
    for(int i=1; i<=n; i++)d[i][0]=cnt[i];
    for(int j=1; (1<<j)<=n; j++)
        for(int i=1; i+(1<<j)-1<=n; i++)
            d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}

int RMQ(int l,int r)
{
    if(l>r)return 0;
    int k=0;
    while(1<<(k+1)<=r-l+1)k++;
    return max(d[l][k],d[r-(1<<k)+1][k]);
}

int main()
{
    int n,m,q,x;
    while(scanf("%d",&n)&&n)
    {
        scanf("%d",&q);
        memset(right,0,sizeof right);
        m=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &x);
            if(!m||value[m]!=x)
            {
                value[++m]=x;
                cnt[m]=1;
            }
            else cnt[m]++;
            num[i]=m;
        }
        cnt[m+1]=n;
        int k=1,tmpleft=1,tmpright=cnt[1];
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=cnt[i];j++)
            {
                left[k]=tmpleft;
                right[k++]=tmpright;
            }
            tmpleft+=cnt[i];
            tmpright+=cnt[i+1];
        }
        RMQ_init(m);
        
        int l,r;
        
        while(q--)
        {
            scanf("%d%d",&l,&r);
            if(left[l]==left[r])
            	printf("%d\n",r-l+1);
            else 
            	printf("%d\n",max(max(right[l]-l+1,r-left[r]+1),RMQ(num[l]+1,num[r]-1)));
        }
    }
    return 0;
}
