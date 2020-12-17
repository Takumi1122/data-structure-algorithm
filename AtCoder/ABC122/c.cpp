#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, q;
  string s;
  cin >> n >> q >> s;

  vector<int> sum(n + 1, 0);
  rep(i, n - 1) {
    if (s[i] == 'A' && s[i + 1] == 'C') {
      sum[i + 2]++;
    }
  }
  rep(i, n) sum[i + 1] += sum[i];

  rep(i, q) {
    int l, r;
    cin >> l >> r;
    cout << sum[r] - sum[l] << endl;
  }
  return 0;
}