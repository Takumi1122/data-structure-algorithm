#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// r -> p, s -> r, p -> s
int main() {
  int n, k, r, s, p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;

  auto score = [&](int i) {
    if (t[i] == 'r')
      return p;
    else if (t[i] == 's')
      return r;
    else
      return s;
  };

  ll res = 0;
  rep(i, k) {
    bool last = false;
    for (int j = i; j < n; j += k) {
      if (j >= k && t[j - k] == t[j] && last)
        last = false;
      else
        res += score(j), last = true;
    }
  }
  cout << res << endl;
}