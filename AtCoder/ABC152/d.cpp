#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

// Aを固定したときのBの個数は、Aの「最上位の値」と「一の位の値」のみに依存する

// (a,b) = (xの一の位の値, xの最上位の値)
P f(int x) {
  int a = x % 10;
  int b = 0;
  while (x) {
    b = x;
    x /= 10;
  }
  return P(a, b);
}

int main() {
  int n;
  cin >> n;

  map<P, int> freq;
  for (int i = 1; i <= n; ++i) {
    P p = f(i);
    freq[p]++;
  }

  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    P p = f(i);
    P q(p.second, p.first);
    ans += freq[q];
  }
  cout << ans << endl;
  return 0;
}
