#include <bits/stdc++.h>

using namespace std;

const int MAXC = 6;
const int MAXN = 1 << MAXC;
const int MOD = 4242;

using row = vector<int>;
using matrix = vector<row>;

matrix _aux(MAXN, row(MAXN));

void mult(matrix& res, const matrix& a, const matrix& b) {
  int n = a.size();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      _aux[i][j] = 0;
      for (int k = 0; k < n; ++k) {
        _aux[i][j] += (a[i][k] * b[k][j]) % MOD;
      }
      _aux[i][j] %= MOD;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      res[i][j] = _aux[i][j];
    }
  }
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int t, n, c;
  string w;

  cin >> t;
  while (t--) {

    cin >> n >> c;
    cin >> w;
    int w_sz = w.size();

    vector<int> cant_go_before(c, 0);
    for (int letter = 0; letter < c; ++letter) {
      // find last occurrence of letter
      int pos = w_sz - 1;
      while (pos && (w[pos] != char(letter+'A'))) pos--;
      // find which letters appear before letter
      while (pos > 0) {
        pos--;
        cant_go_before[letter] |= (1 << (w[pos]-'A'));
      }
      cout << cant_go_before[letter] << endl;
    }

    int num_masks = 1 << c;
    matrix A(num_masks, row(num_masks));
    matrix R(num_masks, row(num_masks));

    for (int i = 0; i < num_masks; ++i) {
      R[i][i] = 1;
    }

    // For each state find which states might have anteceded it.
    // (i, previous_mask) -> (i+1, mask)
    // A[mask][...] * B_0 = B_1[mask]
    for (int mask = 0; mask < num_masks; ++mask) {
      // for each letter on mask set it as the last letter on the the string
      for (int letter = 0; letter < c; ++letter) 
      if (mask & (1<<letter)) 
      {
        // all letters could already be there.. previous_mask = mask
        if (!(cant_go_before[letter] & mask)) 
        {
          // we can only come from previous_mask if all the letters there can
          // go before the last letter
          A[mask][mask]++;
        }
        // or the last letter might be the first occurrence so we remove
        // the letter from the mask
        int previous_mask = mask ^ (1 << letter);
        if (!(cant_go_before[letter] & previous_mask)) 
        {
          A[previous_mask][mask]++;
        }
      }
    }

    while (n) {
      if (n & 1) mult(R, A, R);
      mult(A, A, A);
      n >>= 1;
    }

    int res = 0;
    for (int mask = 0; mask < num_masks; ++mask) {
      res = (res + R[0][mask]) % MOD;
    }
    cout << res << "\n";
  }

  return 0;
}
