#include <bits/stdc++.h>
using namespace std;
#define	WLEN	  32	/* word length */
#define	LOGWLEN	  5	/* log word length -- round(LOG2(WLEN) */
#define SMAX	  65536	/* maximum string length -- multiple of WLEN */
#define BITMAX	  2048	/* maximum bit string length -- round(SMAX/WLEN) */
#define	ALPHASIZE 26	/* alphabet size */

typedef unsigned int WORD;
typedef short unsigned int INDEX;	/* i: alpha[i] == char */




int nwords;				/* no. of words for bits */
WORD bit1[BITMAX];
WORD bit2[BITMAX];
WORD a_strings[ALPHASIZE][BITMAX];
WORD *pb1, *pb2, *t1;

WORD bitmask[LOGWLEN] = {0x55555555, 0x33333333, 0x0f0f0f0f, 0x00ff00ff, 0x0000ffff};
INDEX stringa[SMAX];
INDEX stringb[SMAX];
char alpha[ALPHASIZE];

void alphastrings(INDEX *s, int len)
{
	register INDEX *p;
	register int i, j;

	for (i = 0; i < ALPHASIZE; i++)
		for (j = 0; j < nwords; j++)
			a_strings[i][j] = 0;
	p =  s;
	j = len;
	for (i = 0; i < j; i++)
		a_strings[*(p++)][i/WLEN] |=  1 << (i % WLEN);

	return;
}

int bitcount(WORD *wp)
{
	register WORD w, count;
	register int j, rshift, i;

	count = 0;
	for (i = 0; i < nwords; i++) {
		w = *(wp++);
		rshift = 1;
		for (j = 0; j < LOGWLEN; j++) {
			w = (w & bitmask[j]) + ((w & ~bitmask[j]) >> rshift);
			rshift <<= 1;
		}
		count += w;
	}
	return (count);
}
void bitops(WORD *last, WORD *cur, INDEX index)
{
	register WORD x, y;
	register int j;
	register WORD *a_s;
	register WORD top_borrow, bottombit;

	a_s = &a_strings[index][0];
	bottombit = 1;
	for (j = 0; j < nwords; j++) {
		y = *(last++);
		x =  y | *(a_s++);
		top_borrow = (y >> (WLEN - 1)) & 0x1;
		y = ((y << 1) | bottombit);
		if (x < y)
			top_borrow = 1;
		*(cur++) = x & ((x - y) ^ x);
		bottombit = top_borrow;
	}
	return;
}

int bitlcs( INDEX *a, int lena, INDEX *b ,int lenb)
{
	register int i;
	register INDEX *pbstring;
	register int j, k;

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

int main()
{
	string a,b;
	cin >> a >> b;
	for(int i = 0; i < a.size(); i++)
	{
		stringa[i] = a[i] - 'a';
	}

	for(int i = 0; i < b.size(); i++)
	{
		stringb[i] = b[i] - 'a';
	}
	for(int i = 0; i < 26; i++)
		alpha[i] = i + 'a';
	cout << bitlcs(stringa,(int)(a.size()),stringb,(int)(b.size())) << endl;
}
