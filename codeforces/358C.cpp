#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

int n;
int a[100001];
int num1,num2,num3,cnt;

priority_queue < int , vector <int> > Q;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]); num1=num2=num3=0; int last=i;
        while (a[i]!=0&&i+1<=n)
        {
            Q.push(a[i]);
            scanf("%d",&a[++i]);
        }
        cnt=0;
        if (!Q.empty()) { num1=Q.top(); cnt++; Q.pop(); }
        if (!Q.empty()) { num2=Q.top(); cnt++; Q.pop(); }
        if (!Q.empty()) { num3=Q.top(); cnt++; Q.pop(); }
        for (int j=last;j<=i;j++)
        {
            if (num1&&a[j]==num1) { printf("pushStack\n"); num1=0; } else
            if (num2&&a[j]==num2) { printf("pushQueue\n"); num2=0; } else
            if (num3&&a[j]==num3) { printf("pushFront\n"); num3=0; } else
            if (a[j]!=0) printf("pushBack\n");
        }
        if (a[i]==0)
        {
            if (cnt==0) printf("%d\n",cnt); else printf("%d ",cnt);
            if (cnt>=1) printf("popStack%c",cnt==1?'\n':' ');
            if (cnt>=2) printf("popQueue%c",cnt==2?'\n':' ');
            if (cnt>=3) printf("popFront\n");
        }
        while (!Q.empty()) Q.pop();
    }
//    for (;;);
}
