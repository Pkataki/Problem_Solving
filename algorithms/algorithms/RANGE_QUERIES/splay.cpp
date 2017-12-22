struct SplayTree {
    int n;
    int cnt;
    int top;
    int root;
    int sz[N];
    int ls[N];
    int rs[N];
    int ss[N];
    int pre[N];
    int val[N];
    int sum[N];
    int lzy2[N];
    int pool[N];
    int ch[N][2];
    bool lzy1[N];
 
    void rotate(int x, int f) {
        int y = pre[x];
        int z = pre[y];
        push_down(y);
        ch[y][!f] = ch[x][f];
        pre[ch[x][f]] = y;
        ch[x][f] = y;
        pre[y] = x;
        pre[x] = z;
        if (pre[x] != 0) {
            ch[z][ch[z][1] == y ? 1 : 0] = x;
        }
        push_up(y);
    }
 
    void splay(int x, int goal) {
        push_down(x);
        while (pre[x] != goal) {
            if (pre[pre[x]] == goal) {
                rotate(x, ch[pre[x]][0] == x ? 1 : 0);
            } else {
                int y = pre[x];
                int z = pre[y];
                int f = ch[z][0] == y ? 1 : 0;
                if (ch[y][f] == x) {
                    rotate(x, !f);
                } else {
                    rotate(y, f);
                }
                rotate(x, f);
            }
        }
        push_up(x);
        if (goal == 0) {
            root = x;
        }
    }
 
    void rotateto(int k, int goal) {
        int x = root;
        push_down(x);
        while (sz[ch[x][0]] != k) {
            if (k < sz[ch[x][0]]) {
                x = ch[x][0];
            } else {
                k -= sz[ch[x][0]] + 1;
                x = ch[x][1];
            }
            push_down(x);
        }
        splay(x, goal);
    }
 
    void clear() {
        n = root = 0;
        val[0] = ls[0] = rs[0] = ss[0] = -INF;
        ch[0][0] = ch[0][1] = pre[0] = sz[0] = 0;
        sum[0] = 0;
        lzy1[0] = 0;
        lzy2[0] = -INF;
        newnode(root, -INF);
        newnode(ch[root][1], -INF);
        pre[n] = root;
        sz[root] = 2;
    }
 
    void newnode(int &x, int c) {
        if (top != 0) {
            x = pool[--top];
        } else {
            x = ++n;
        }
        sz[x] = 1;
        ch[x][0] = ch[x][1] = pre[x] = 0;
        val[x] = ls[x] = rs[x] = ss[x] = sum[x] = c;
        lzy1[x] = 0;
        lzy2[x] = -INF;
    }
 
    void push_up(int x) {
        int lx = ch[x][0];
        int rx = ch[x][1];
        sz[x] = 1 + sz[lx] + sz[rx];
        sum[x] = val[x] + sum[lx] + sum[rx];
        ls[x] = max(ls[lx], sum[lx] + val[x] + max(0, ls[rx]));
        rs[x] = max(rs[rx], sum[rx] + val[x] + max(0, rs[lx]));
        ss[x] = max(0, rs[lx]) + val[x] + max(0, ls[rx]);
        ss[x] = max(ss[x], max(ss[lx], ss[rx]));
    }
 
    void update_rev(int x) {
        if (x == 0) {
            return;
        }
        lzy1[x] ^= 1;
        swap(ls[x], rs[x]);
        swap(ch[x][0], ch[x][1]);
    }
 
    void update_same(int x, int v) {
        if (x == 0) {
            return;
        }
        val[x] = v;
        lzy2[x] = v;
        sum[x] = v * sz[x];
        ss[x] = ls[x] = rs[x] = max(v, v * sz[x]);
    }
 
    void push_down(int x) {
        if (lzy1[x] != 0) {
            update_rev(ch[x][0]);
            update_rev(ch[x][1]);
            lzy1[x] = 0;
        }
        if (lzy2[x] != -INF) {
            update_same(ch[x][0], lzy2[x]);
            update_same(ch[x][1], lzy2[x]);
            lzy2[x] = -INF;
        }
    }
 
    void init(int pos, int tot) {
        clear();
        cnt = tot;
        top = 0;
        rotateto(pos, 0);
        rotateto(pos + 1, root);
        build(ch[ch[root][1]][0], 1, tot, ch[root][1]);
        push_up(ch[root][1]);
        push_up(root);
    }
 
    void build(int &x, int l, int r, int f) {
        if (l > r) {
            return;
        }
        push_down(f);
        int mid = (l + r) / 2;
        newnode(x, num[mid]);
        build(ch[x][0], l, mid - 1, x);
        build(ch[x][1], mid + 1, r, x);
        pre[x] = f;
        push_up(x);
    }
 
    void ins(int pos, int len) {
        cnt += len;
        rotateto(pos, 0);
        rotateto(pos + 1, root);
        build(ch[ch[root][1]][0], 1, len, ch[root][1]);
        push_up(ch[root][1]);
        push_up(root);
    }
 
    void erase(int x) {
        if (x == 0) {
            return;
        }
        pool[top++] = x;
        erase(ch[x][0]);
        erase(ch[x][1]);
    }
 
    void del(int l, int r) {
        rotateto(l - 1, 0);
        rotateto(r + 1, root);
        int key = ch[ch[root][1]][0];
        ch[ch[root][1]][0] = 0;
        cnt -= sz[key];
        erase(key);
        push_up(ch[root][1]);
        push_up(root);
    }
 
    void change(int l, int r, int c) {
        rotateto(l - 1, 0);
        rotateto(r + 1, root);
        int key = ch[ch[root][1]][0];
        update_same(key, c);
        push_up(ch[root][1]);
        push_up(root);
    }
 
    void flip(int l, int r) {
        rotateto(l - 1, 0);
        rotateto(r + 1, root);
        int key = ch[ch[root][1]][0];
        update_rev(key);
    }
 
    int get_sum(int l, int r) {
        rotateto(l - 1, 0);
        rotateto(r + 1, root);
        int key = ch[ch[root][1]][0];
        return sum[key];
    }
 
    int max_sum() {
        rotateto(0, 0);
        rotateto(cnt + 1, root);
        int key = ch[ch[root][1]][0];
        return ss[key];
    }
} splay;
 
void work() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }
    splay.init(0, n);
    for (int it = 0; it < m; it++) {
        scanf("%s", op);
        if (strcmp(op, "INSERT") == 0) {
            scanf("%d %d", &a, &n);
            for (int i = 1; i <= n; i++) {
                scanf("%d", &num[i]);
            }
            splay.ins(a, n);
        } else if (strcmp(op, "DELETE") == 0) {
            scanf("%d %d", &a, &b);
            splay.del(a, a + b - 1);
        } else if (strcmp(op, "SAME") == 0) {
            scanf("%d %d %d", &a, &b, &c);
            splay.change(a, a + b - 1, c);
        } else if (strcmp(op, "REVERSE") == 0) {
            scanf("%d %d", &a, &b);
            splay.flip(a, a + b - 1);
        } else if (strcmp(op, "GET") == 0) {
            scanf("%d %d", &a, &b);
            printf("%d\n", splay.get_sum(a, a + b - 1));
        } else if (strcmp(op, "MAX") == 0) {
            printf("%d\n", splay.max_sum());
        }
    }
}
