
vector <long long> m;
vector <long long> c;
int sz, pointer;

bool bad (int l1, int l2, int l3) {
    return (m[l1] - m[l2]) * (c[l3] - c[l1]) <= (c[l2] - c[l1]) * (m[l1] - m[l3]);
}

void add (long long m0, long long c0) {
    ++sz;
    m.push_back(m0);
    c.push_back(c0);
    while (sz >= 3 && bad(sz - 3, sz - 2, sz - 1)) 
    {
		--sz;
		m.erase(m.end() - 2);
		c.erase(c.end() - 2);
    }
}

long long query (long long x) {
    if (pointer >= sz) pointer = sz - 1;
    while (pointer < (sz - 1) && m[pointer] * x + c[pointer] >= m[pointer + 1] * x + c[pointer + 1]) {
		++pointer;
    }
    return m[pointer] * x + c[pointer];
}
void clear()
{
	m.clear();
	c.clear();
	sz = 0;
	pointer = 0;
}

