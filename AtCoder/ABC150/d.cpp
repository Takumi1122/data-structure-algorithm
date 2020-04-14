#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int GCD(int x, int y) {
  if (y == 0)
    return x;
  else
    return GCD(y, x % y);
}

int LCM(int a, int b) {
  int g;
  g = GCD(a, b);
  return a * b / g;
}

int GCD_N(vector<int> &a) {
  int g;
  g = a[0];
  for (int i = 1; i < a.size(); i++) {
    g = GCD(g, a[i]);
  }
  return g;
}

int LCM_N(vector<int> &a) {
  int l;
  l = a[0];
  for (int i = 1; i < a.size(); i++) {
    l = LCM(l, a[i]);
  }
  return l;
}

bool is_pow2(int x) {
  if (x == 0) {
    return false;
  }
  return (x & (x - 1)) == 0;
}

int is_pow2_n(vector<int> &a) {
  bool l = true;
  for (int i = 1; i < a.size(); i++) {
    l = is_pow2(a[i]);
    if (!l) break;
  }
  return l;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int l = LCM_N(a) / 2;
  int c = 0;
  for (int i = 1; i <= m / l; i++) {
    int l2 = l * i;
    if (l2 % 2 == 0) continue;
    c++;
  }
  cout << c << endl;
  return 0;
}