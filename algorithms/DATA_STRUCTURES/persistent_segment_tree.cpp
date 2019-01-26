
const int maxn = 300005;
int tree[30*maxn], L[30*maxn], R[30*maxn];
int sz = 0;
int root[maxn];

int update(int pre, int l, int r, int pos, int val)
{
    if(l > r || pos < l || pos > r )
        return pre;
    int no = ++sz;
    tree[no] = tree[pre];
    L[no] = L[pre];
    R[no] = R[pre];
    
    if(l == r && l == pos)
    {
        tree[no] += val;
        R[no] = L[no] = 0;
        return no;
    }
    int mid = (l + r) >> 1;
    
    L[no] = update(L[pre], l, mid, pos, val);
    R[no] = update(R[pre], mid+1, r, pos, val);
    
    tree[no] = tree[L[no]] + tree[R[no]];
    
    return no;
}

int query(int no, int no1 , int l , int r, int k)
{
    if( l > r )
        return 0;
    if(l == r)
    {
        return l;   
    }
    
    int mid = (l + r) >> 1;
    
    int count = tree[L[no]] - tree[L[no1]];
    
    if(k < count)
        return query(L[no],L[no1],l,mid,k);
    return query(R[no],R[no1],mid+1,r,k-count);
}


