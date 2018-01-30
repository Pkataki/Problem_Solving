#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, tot = 1, cnt, ans[100010], len[100010];
char s[100010][1010], s2[10010];

struct node
{
    int tr[30];
    int id;
}e[1000010];

void insert(char *ss, int x)
{
    int len = strlen(ss);
    int u = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        char ch = ss[i];
        if (ch < 'a' || ch > 'z')
            ch += 'a' - 'A';
        int p = ch - 'a';
        if (!e[u].tr[p])
            e[u].tr[p] = ++tot;
        u = e[u].tr[p];
    }
    e[u].id = x;
}

void solve(int dep)
{
    cout << dep << endl;
    if (dep == n)
    {
        for (int i = 1; i < cnt; i++)
            cout << s[ans[i]] << " ";
        cout << s[ans[cnt]] << endl;
        exit(0);
    }
    int u = 1,i;
    for (i = dep; i < n; i++)
    {
        int p = s2[i] - 'a';
        if (!e[u].tr[p])
            break;
        u = e[u].tr[p];
        if (e[u].id)
        {
            ans[++cnt] = e[u].id;
            solve(dep + len[e[u].id]);
            --cnt;
        }
    }
}

int main()
{
    scanf("%d", &n);
    scanf("%s", s2 );
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", s[i]);
        len[i] = strlen(s[i]);
        insert(s[i], i);
    }
    solve(0);

    return 0;
}