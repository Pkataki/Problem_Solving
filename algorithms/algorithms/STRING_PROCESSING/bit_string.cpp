#include <bits/stdc++.h>

using namespace std;

//SOLVE IN (|A|*|B|)/WLEN

#define	WLEN	  64	/* word length */
#define	LOGWLEN	  6	/* log word length -- round(LOG2(WLEN) */
#define SMAX	  65536	/* maximum string length -- multiple of WLEN */
#define BITMAX	  1024	/* maximum bit string length -- round(SMAX/WLEN) */
#define	ALPHASIZE 26	/* alphabet size */
 
typedef unsigned long long WORD;
 
 
 
int nwords;				/* no. of words for bits */
WORD bit1[BITMAX];
WORD bit2[BITMAX];
WORD a_strings[ALPHASIZE][BITMAX];
WORD *pb1, *pb2, *t1;
 
WORD bitmask[LOGWLEN] = {6148914691236517205ULL, 3689348814741910323ULL, 1085102592571150095ULL, 71777214294589695ULL, 281470681808895ULL, 4294967295ULL};
WORD stringa[SMAX];
WORD stringb[SMAX];
char alpha[ALPHASIZE];
 
void alphastrings(WORD *s, int len)
{
	 WORD *p;
	 WORD i, j;
 
	for (i = 0; i < ALPHASIZE; i++)
		for (j = 0; j < nwords; j++)
			a_strings[i][j] = 0;
	p =  s;
	j = len;
	for (i = 0; i < j; i++)
		a_strings[*(p++)][i/WLEN] |=  1ULL << (i % WLEN);
 
	return;
}
 
int bitcount(WORD *wp)
{
	 WORD w, count;
	 WORD j, rshift, i;
 
	count = 0;
	for (i = 0; i < nwords; i++) {
		w = *(wp++);
		rshift = 1;
		for (j = 0; j < LOGWLEN; j++) {
			w = (w & bitmask[j]) + ((w & ~bitmask[j]) >> rshift);
			rshift <<= 1ULL;
		}
		count += w;
	}
	return (count);
}
 
void bitops(WORD *last, WORD *cur, WORD index)
{
	 WORD x, y;
	 WORD j;
	 WORD *a_s;
	 WORD top_borrow, bottombit;
 
	a_s = &a_strings[index][0];
	bottombit = 1;
	for (j = 0; j < nwords; j++) {
		y = *(last++);
		x =  y | *(a_s++);
		top_borrow = (y >> (WLEN - 1)) & 1ULL;
		y = ((y << 1ULL) | bottombit);
		if (x < y)
			top_borrow = 1;
		*(cur++) = x & ((x - y) ^ x);
		bottombit = top_borrow;
	}
	return;
}
 
int bitlcs( WORD *a, int lena, WORD *b ,int lenb)
{
	 WORD i;
	 WORD *pbstring;
	 WORD j, k;
 
	nwords = (lena + WLEN - 1) / WLEN;
 
	alphastrings(a, lena);
 
	pb1 = &bit1[0];
	for (i = 0; i < nwords; i++)
		*pb1++ = 0;		/*** bit1[i] = 0; ***/
	pb1 = &bit1[0]; pb2 = &bit2[0];
	pbstring = b;
 
	for (i = 1; i <= lenb; i++) {
		bitops(pb1, pb2, *(pbstring++));
 
		t1 = pb1; pb1 = pb2; pb2 = t1;
	}
 
	return (bitcount(pb1));
}
 
void process(string &a, string &b){
	for(int i = 0; i < a.size(); i++){
		stringa[i] = a[i];
	}
 
	for(int i = 0; i < b.size(); i++){
		stringb[i] = b[i];
	}
}

int main(){
	string a, b;

	cin >> a >> b;

	process(a, b);

	cout << bitlcs(stringa, (int)a.size(), stringb ,(int)b.size()) << '\n';
}