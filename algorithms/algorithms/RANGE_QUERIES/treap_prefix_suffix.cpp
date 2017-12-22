#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int64;
typedef unsigned long long uint64;

 #define getchar_unlocked getchar 
 #define putchar_unlocked putchar 

/*  
inline bool read( int &n ) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
    if( c == EOF) { n = -1; return false; }
    while (!('0' <= c && c <= '9')) {
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    n = (neg ? (-n) : (n));
    return true;
}
 
inline void writeInt(int n){ 
    register int idx = 20; 
    if( n < 0 ) putchar_unlocked('-'); 
    n = labs(n); 
    char out[21]; 
    out[20] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
}
 */
 
struct tri{
    int sum, sumLo, sumHi, ans, ok;
    tri( int sum = -1e9, int sumLo = -1e9, int sumHi = -1e9, int ans = -1e9 ) :
    sum(sum), sumLo(sumLo), sumHi(sumHi), ans(ans), ok(0) { }
};
 
inline tri merge( tri lo, tri hi ){
    if( lo.ans == -1e9  ) return hi;
    if( hi.ans == -1e9  ) return lo;
 
    tri novo;
    novo.ok = 1;
    novo.sum = lo.sum + hi.sum;
    novo.sumLo = max(lo.sumLo, lo.sum + hi.sumLo);
    novo.sumHi = max(hi.sumHi, hi.sum + lo.sumHi);
    novo.ans = max(max(lo.ans, hi.ans), lo.sumHi + hi.sumLo);
 
    return novo;
} 
 
struct node_t {
    int key, pr, sz;
    tri seg;
 
    node_t *l, *r;
        
    node_t(int k) : key(k), pr(rand()), sz(0), l(NULL), r(NULL) {}
        
    ~node_t() {
        if(l) delete l;
        if(r) delete r;
    }
};
 
inline void rotate_right(node_t* &t) {
        node_t *n = t->l;
        t->l = n->r;
        n->r = t;
        t = n;
}
  
inline void rotate_left(node_t* &t) {
        node_t *n = t->r;
        t->r = n->l;
        n->l = t;
        t = n;
}
  
inline void fix(node_t* t) {
    if(!t) return;
    t->sz = 1 + ((t->l)?(t->l->sz):(0)) + ((t->r)?(t->r->sz):(0));
    tri lseg, rseg, at = tri(t->key, t->key, t->key, t->key);
    lseg = (t->l)?((t->l->seg)):(tri(-1e9, -1e9, -1e9, -1e9));
    rseg = (t->r)?((t->r->seg)):(tri(-1e9, -1e9, -1e9, -1e9));
    t->seg = merge(lseg, at);
    t->seg = merge(t->seg, rseg);
}
  
inline void insert(node_t* &t, int val, int pos) {
    if(!t) t = new node_t(val);
    else {
        int lsz = ((t->l)?(t->l->sz):(0));
        if (lsz >= pos) insert(t->l, val, pos);
        else insert(t->r, val, pos-lsz-1);
    }
    if (t->l && ((t->l->pr) > (t->pr))) rotate_right(t);
    else if (t->r && ((t->r->pr) > (t->pr))) rotate_left(t);
    fix(t->l); fix(t->r); fix(t);
}
  
inline int p(node_t* t) { return (t) ? (t->pr) : (-1); }
  
inline void erase(node_t* &t, int pos) {
    if(!t) return;
    int lsz = ((t->l)?(t->l->sz):(0));
    if (lsz+1 != pos) {
        if (lsz >= pos) erase(t->l, pos);
        else erase(t->r, pos-lsz-1);
    } 
    else{
        if (!t->l && !t->r) {
            delete t;
            t = NULL;
        }
        else{
            if (p(t->l) < p(t->r)) rotate_left(t);
            else rotate_right(t);
            erase(t, pos);
        }
    }
 
    if (t) { fix(t->l); fix(t->r); fix(t); }
}
  
inline void replace(node_t* t, int pos, int val) {
        if(!t) return;
        
        int lsz = ((t->l)?(t->l->sz):(0));
        if (lsz+1 != pos) {
            if (lsz >= pos) replace(t->l, pos, val);
            else replace(t->r, pos-lsz-1, val);
        } else t->key = val;
        
        fix(t);
}
  
 
int x, y;
inline tri query(node_t* t, int lo, int hi) {
    if (x <= lo && hi <= y) return t->seg;
 
    register int mid = lo + ((t->l)?(t->l->sz):(0)) - 1;
 
    tri q1, q2, ans, at = tri(t->key, t->key, t->key, t->key);
    register bool f1 = false, f2 = false;
 
    if (mid >= lo && mid >= x) { f1 = true; q1 = query(t->l, lo, mid); }
    if (mid+2 <= hi && mid+2 <= y) { f2 = true; q2 = query(t->r, mid+2, hi); }
 
    if (!f1 && !f2) return at;
 
    if (f1 && f2) {
        ans = merge(q1, at);
        return merge(ans, q2);
    }
    else if (f1) {
        if (x <= mid+1 && mid+1 <= y){
            return merge(q1, at);
        }
        else return q1;
    }
    else if (x <= mid+1 && mid+1 <= y) {
        return merge(at, q2);
    } 
    return q2;
}
 
int main(){
    ios::sync_with_stdio(false);
    srand(time(NULL));
    int lo, hi, val, n, q;
    scanf("%d",&n);
    node_t *treap = NULL;
    for( int i = 0; i < n; i++ ){
        scanf("%d",&val);
		insert(treap, val, i);
    }
    scanf("%d",&q);
    for( int i = 0; i < q; i++ ){
        register char op = getchar_unlocked();
        while( op != 'R' && op != 'I' && op != 'D' && op != 'Q' ) op = getchar_unlocked();
        switch(op){
            case 'R':
				scanf("%d",&x);
				scanf("%d",&y);
                replace(treap, x, y);
                break;
            case 'I':
				scanf("%d",&x);
				scanf("%d",&y);
                insert(treap, y, x-1);
                break;
            case 'D':
				scanf("%d",&x);
                erase(treap, x);
                break;
            case 'Q':
				scanf("%d",&x);
				scanf("%d",&y);
                printf("%d\n", query(treap, 1, treap->sz).ans );
                break;
        }
    }
    return 0;
}
