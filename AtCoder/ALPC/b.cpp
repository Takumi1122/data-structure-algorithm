#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, q;
  cin >> n >> q;
  fenwick_tree<ll> fw(n);
  rep(i, n) {
    int a;
    cin >> a;
    fw.add(i, a);
  }

  rep(i, q) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0) {
      fw.add(b, c);
    } else {
      cout << fw.sum(b, c) << endl;
    }
  }
}