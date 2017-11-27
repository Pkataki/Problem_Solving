#include <bits/stdc++.h>

const int N = 100000 + 10;

int n;

struct node {
  node *p, *ch[2];
  inline bool d() { return this == p->ch[1]; }
  inline bool isroot() { return !p || (this != p->ch[0] && this != p->ch[1]); }
};

node pool[N];

inline void rotate(node *u) {
  node *v = u->p;
  bool d = u->d();
  if (!v->isroot()) v->p->ch[v->d()] = u;
  u->p = v->p;
  if (u->ch[!d]) u->ch[!d]->p = v;
  v->ch[d] = u->ch[!d];
  u->ch[!d] = v;
  v->p = u;
}

inline void splay(node *u) {
  while (!u->isroot()) {
    if (u->p->isroot())
      rotate(u);
    else
      (u->d() == u->p->d()) ? (rotate(u->p), rotate(u)) : (rotate(u), rotate(u));
  }
}

inline node* expose(node *u) {
  node *v;
  for (v = NULL; u; v = u, u = u->p) {
    splay(u);
    u->ch[1] = v;
  }
  return v;
}

inline void link(node *u, node *v) {
  splay(u);
  u->p = v;
}

inline void cut(node *u) {
  expose(u);
  splay(u);
  u->ch[0]->p = NULL;
  u->ch[0] = NULL;
}

inline node* lca(node *u, node *v) {
  expose(u);
  return expose(v);
}

int main() {
  scanf("%d", &n);
  int tcase;
  for (scanf("%d", &tcase); tcase--;) 
  {
    static char op[10];
    static int a, b;
    scanf(" %s", op);
    switch (op[1]) 
    {
      case 'i':
        scanf("%d%d", &a, &b);
        link(pool + a, pool + b);
        break;
      case 'u':
        scanf("%d", &a);
        cut(pool + a);
        break;
      case 'c':
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(pool + a, pool + b)  - pool);
        break;
    }
  }
  return 0;
}
