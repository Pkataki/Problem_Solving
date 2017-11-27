#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001000;

string T;

int N, SA[MAXN];
char mask[]={char(128), char(64), char(32), char(16), char(8), char(4), char(2), char(1)};
#define tget(i) ( (t[(i)/8]&mask[(i)%8]) ? 1 : 0 )
#define tset(i, b) t[(i)/8]=(b) ? (mask[(i)%8]|t[(i)/8]) : ((~mask[(i)%8])&t[(i)/8])
#define chr(i) (cs==sizeof(int)?((int*)s)[i]:(( char *)s)[i])
#define isLMS(i) (i>0 && tget(i) && !tget(i-1))
   
// find the start or end of each bucket
void getBuckets( char *s, int *bkt, int n, int K, int cs, bool end) {
  int i, sum=0;
  for(i=0; i<=K; i++) bkt[i]=0; // clear all buckets
  for(i=0; i<n; i++) bkt[chr(i)]++; // compute the size of each bucket
  for(i=0; i<=K; i++) { sum+=bkt[i]; bkt[i]=end ? sum : sum-bkt[i]; }
}
  
// compute SAl
void induceSAl( char *t, int *SA,  char *s, int *bkt,
                int n, int K, int cs, bool end) {
  int i, j;
  getBuckets(s, bkt, n, K, cs, end); // find starts of buckets
  for(i=0; i<n; i++) {
      j=SA[i]-1;
      if(j>=0 && !tget(j)) SA[bkt[chr(j)]++]=j;
  }
}
  
// compute SAs
void induceSAs( char *t, int *SA,  char *s, int *bkt,
                int n, int K, int cs, bool end) {
    int i, j;
    getBuckets(s, bkt, n, K, cs, end); // find ends of buckets
    for( i=n-1; i>=0; i-- ){
        j=SA[i]-1;
        if(j>=0 && tget(j)) SA[--bkt[chr(j)]]=j;
    }
}
  
// find the suffix array SA of s[0..n-1] in {1..K}^n
// require s[n-1]=0 (the sentinel!), n>=2
// use a working space (excluding s and SA) of at most 2.25n+O(1) for a constant alphabet
void SA_IS( char *s, int *SA, int n, int K, int cs) {
  int i, j;
   char *t=( char *)malloc(n/8+1); // LS-type array in bits
  
  // Classify the type of each character
  tset(n-2, 0); tset(n-1, 1); // the sentinel must be in s1, important!!!
  for(i=n-3; i>=0; i--)
    tset(i, (chr(i)<chr(i+1) || (chr(i)==chr(i+1) && tget(i+1)==1))?1:0);
  
  // stage 1: reduce the problem by at least 1/2
  // sort all the S-substrings
  int *bkt = (int *)malloc(sizeof(int)*(K+1)); // bucket array
  getBuckets(s, bkt, n, K, cs, true); // find ends of buckets
  for(i=0; i<n; i++) SA[i]=-1;
  for(i=1; i<n; i++)
    if(isLMS(i)) SA[--bkt[chr(i)]]=i;
  
  induceSAl(t, SA, s, bkt, n, K, cs, false);
  induceSAs(t, SA, s, bkt, n, K, cs, true);
  free(bkt);
  
  // compact all the sorted substrings into the first n1 items of SA
  // 2*n1 must be not larger than n (proveable)
  int n1=0;
  for(i=0; i<n; i++)
    if(isLMS(SA[i])) SA[n1++]=SA[i];
  
  // find the lexicographic names of all substrings
  for(i=n1; i<n; i++) SA[i]=-1; // init the name array buffer
  int name=0, prev=-1;
  for(i=0; i<n1; i++) {
    int pos=SA[i]; bool diff=false;
    for(int d=0; d<n; d++)
      if(prev==-1 || chr(pos+d)!=chr(prev+d) || tget(pos+d)!=tget(prev+d))
      { diff=true; break; }
      else if(d>0 && (isLMS(pos+d) || isLMS(prev+d))) break;
    if(diff) { name++; prev=pos; }
    pos=(pos%2==0)?pos/2:(pos-1)/2;
    SA[n1+pos]=name-1;
  }
  for(i=n-1, j=n-1; i>=n1; i--)
      if(SA[i]>=0) SA[j--]=SA[i];
  
  // stage 2: solve the reduced problem
  // recurse if names are not yet unique
  int *SA1=SA, *s1=SA+n-n1;
  if(name<n1)
    SA_IS(( char*)s1, SA1, n1, name-1, sizeof(int));
  else // generate the suffix array of s1 directly
    for(i=0; i<n1; i++) SA1[s1[i]] = i;
  
  // stage 3: induce the result for the original problem
  bkt = (int *)malloc(sizeof(int)*(K+1)); // bucket array
  // put all left-most S characters into their buckets
  getBuckets(s, bkt, n, K, cs, true); // find ends of buckets
  for(i=1, j=0; i<n; i++)
    if(isLMS(i)) s1[j++]=i; // get p1
  for(i=0; i<n1; i++) SA1[i]=s1[SA1[i]]; // get index in s
  for(i=n1; i<n; i++) SA[i]=-1; // init SA[n1..n-1]
  for(i=n1-1; i>=0; i--) {
      j=SA[i]; SA[i]=-1;
      SA[--bkt[chr(j)]]=j;
  }
  induceSAl(t, SA, s, bkt, n, K, cs, false);
  induceSAs(t, SA, s, bkt, n, K, cs, true);
  free(bkt); free(t);
}
  
int ranking[MAXN];
int lcp[MAXN];

void compute_lcp( int n ){
    int i, j, h = 0;
    for (i = 0; i != n; ++i) { ranking[SA[i]] = i; }
    for (i = 0; i != n; ++i) if (ranking[i] > 0) {
        j = SA[ranking[i]-1];
        while (T[i+h] > 'Z' && T[i+h] == T[j+h]) { h++; }
        lcp[ranking[i]] = h;
        if (h > 0) { h--; }
    }
}
int idx[MAXN];
char s1[100005];
int main()
{
    int last = 0;
    int id =0;
    int k = 0;
    while(scanf("%s",s1) != EOF)
    {
        string s2 = s1;
        T += (s2+char(k+'A'));
        k++;
        for(int i = 0; i < s2.size() ; i++)
            idx[last++] = id;
        id++;
        idx[last++] = id++;
    }
    idx[last] = id;
    T[N++] = '.';
    N = T.size();
    
    SA_IS( (char *)T.data(), SA, N, 150, 83 );

    compute_lcp(N);
    
    int lo = 0;
    int hi = 100000;
    int ans = 0;

  //  for(int i = 0; i < T.size(); i++) cout << T.substr(SA[i]) << " " << lcp[i] << endl; 
    while(lo <= hi)
    {
        int mid = (lo + hi) >> 1;
      
        bool ok  = 0;
        for(int i = 0 ; i < T.size(); i++)
        {
            if(lcp[i] > 0 && lcp[i] >= mid)
            {
                int j = i+1;


                int mask = (1 << idx[SA[i-1]]) | (1 << idx[SA[i]]);

                while(lcp[j] > 0 && lcp[j] >= mid && j < T.size())
                {

                    mask |= (1 << idx[SA[j]]);
                    j++;

                }
                i = j-1;
                if(__builtin_popcount(mask) >= k)
                {
                    ok = 1;
                    break;
                }
            }
        }
        if(ok)
        {
            ans = max(ans,mid);
            lo = mid+1;
        }
        else
            hi = mid-1;

    }
    cout << ans << '\n';
    return 0;
}
