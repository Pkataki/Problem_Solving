int fastpow(int base, int d, int n) {
    int ret = 1;
    for (long long pow = base; d > 0; d >>= 1, pow = (pow * pow) % n)
        if (d & 1)
            ret = (ret * pow) % n;
    return ret;
}

bool miller_rabin(int n, int base) {
    if (n <= 1) return false;
    if (n % 2 == 0) return n == 2;

    int s = 0, d = n - 1;
    while (d % 2 == 0) d /= 2, ++s;

    int base_d = fastpow(base, d, n);
    if (base_d == 1) return true;
    int base_2r = base_d;

    for (int i = 0; i < s; ++i) {
        if (base_2r == 1) return false;
        if (base_2r == n - 1) return true;
        base_2r = (long long)base_2r * base_2r % n;
    }

    return false;
}

/*
    if n < 2,047, it is enough to test a = 2;
    if n < 1,373,653, it is enough to test a = 2 and 3;
    if n < 9,080,191, it is enough to test a = 31 and 73;
    if n < 25,326,001, it is enough to test a = 2, 3, and 5;
    if n < 3,215,031,751, it is enough to test a = 2, 3, 5, and 7;
    if n < 4,759,123,141, it is enough to test a = 2, 7, and 61;
    if n < 1,122,004,669,633, it is enough to test a = 2, 13, 23, and 1662803;
    if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11;
    if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13;
    if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.
*/

bool isprime(int n) {
    if (n == 2 || n == 7 || n == 61) return true;
    return miller_rabin(n, 2) && miller_rabin(n, 7) && miller_rabin(n, 61);
}
