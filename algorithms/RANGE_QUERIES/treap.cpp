struct Node;
typedef pair <Node*, Node*> Pair;
 
Node *null, *root;
 
struct Node {
    int sz;
    int mn;
    int val;
    int lzy1;
    int lzy2;
    Node *lft;
    Node *rht;
    Pair split(int);
 
    void add(int v) {
        if (this == null) {
            return;
        }
        mn += v;
        val += v;
        lzy1 += v;
    }
 
    Node *pushup() {
        sz = lft->sz + 1 + rht->sz;
        mn = min(min(lft->mn, rht->mn), val);
        return this;
    }
 
    Node *pushdown() {
        if (this == null) {
            return this;
        }
        if (lzy1 != 0) {
            lft->add(lzy1);
            rht->add(lzy1);
            lzy1 = 0;
        }
        if (lzy2 != 0) {
            swap(lft, rht);
            if (lft != null) {
                lft->lzy2 ^= 1;
            }
            if (rht != null) {
                rht->lzy2 ^= 1;
            }
            lzy2 = 0;
        }
        return this;
    }
};
 
bool random(int a, int b) {
    return double(rand()) / RAND_MAX < (double) a / (a + b);
}
 
Node *merge(Node *p, Node *q) {
    if (p == null) {
        return q;
    }
    if (q == null) {
        return p;
    }
    if (random(p->sz, q->sz)) {
        p->pushdown();
        p->rht = merge(p->rht, q);
        return p->pushup();
    }
    q->pushdown();
    q->lft = merge(p, q->lft);
    return q->pushup();
}
 
Pair Node::split(int need) {
    if (this == null) {
        return make_pair(null, null);
    }
    pushdown();
    if (lft->sz >= need) {
        Pair ret = lft->split(need);
        lft = null;
        pushup();
        return make_pair(ret.first, merge(ret.second, this));
    }
    Pair ret = rht->split(need - (lft->sz + 1));
    rht = null;
    pushup();
    return make_pair(merge(this, ret.first), ret.second);
}
 
int cnt;
Node data[N];
 
Node *newnode(int c) {
    Node *x;
    x = &data[cnt++];
    x->lft = x->rht = null;
    x->sz = 1;
    x->lzy1 = x->lzy2 = 0;
    x->val = x->mn = c;
    return x;
}
 
void init() {
    cnt = 1;
    null = &data[0];
    null->sz = 0;
    null->val = null->mn = INF;
    null->lzy1 = null->lzy2 = 0;
    null->lft = null->rht = null;
}
 
void print(Node *rt) {
    if (rt == null) {
        return;
    }
    print(rt->lft);
    printf("%d ", rt->val);
    print(rt->rht);
}
 
void solve() {
    init();
    root = null;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        root = merge(root, newnode(a));
    }
    scanf("%d", &m);
    for (int it = 0; it < m; it++) {
        scanf("%s", ord);
        if (strcmp(ord, "ADD") == 0) {
            scanf("%d %d %d", &from, &to, &by);
            Pair ret1 = root->split(from - 1);
            Pair ret2 = ret1.second->split(to - from + 1);
            ret2.first->add(by);
            root = merge(ret1.first, merge(ret2.first, ret2.second));
        } else if (strcmp(ord, "MIN") == 0) {
            scanf("%d %d", &from, &to);
            Pair ret1 = root->split(from - 1);
            Pair ret2 = ret1.second->split(to - from + 1);
            printf("%d\n", ret2.first->mn);
            root = merge(ret1.first, merge(ret2.first, ret2.second));
        } else if (strcmp(ord, "DELETE") == 0) {
            scanf("%d", &from);
            Pair ret1 = root->split(from - 1);
            Pair ret2 = ret1.second->split(1);
            root = merge(ret1.first, ret2.second);
        } else if (strcmp(ord, "INSERT") == 0) {
            scanf("%d %d", &from, &by);
            Pair ret1 = root->split(from);
            root = merge(merge(ret1.first, newnode(by)), ret1.second);
        } else if (strcmp(ord, "ROTATE") == 0) {
            scanf("%d %d %d", &from, &to, &by);
            int len = (to - from + 1);
            by = (by % len + len) % len;
            Pair ret1 = root->split(from - 1);
            Pair ret2 = ret1.second->split(to - from + 1);
            Pair ret3 = ret2.first->split(to - from + 1 - by);
            root = merge(ret1.first, merge(merge(ret3.second, ret3.first), ret2.second));
        } else if (strcmp(ord, "REVERSE") == 0) {
            scanf("%d %d", &from, &to);
            Pair ret1 = root->split(from - 1);
            Pair ret2 = ret1.second->split(to - from + 1);
            ret2.first->lzy2 = 1;
            root = merge(ret1.first, merge(ret2.first, ret2.second));
        }
    }
}
