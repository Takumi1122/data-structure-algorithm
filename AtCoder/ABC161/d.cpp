#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k;
  int c = 0;
  cin >> k;
  vector<ll> a;
  rep(i, 3234566667) {
    int num, mod;
    int j = 0;
    bool b = true;
    vector<int> p;
    while (num >= 1) {
      mod = num % 10;  // 一の位の余り
      num = num / 10;  // 取得済みの余りを"num"から除去
      p[j++] = mod;
    }
    rep(t, p.size() - 1) {
      if (i < 10) {
        break;
      }
      if (abs(p[t] - p[t + 1]) > 1) {
        b = false;
        break;
      }
    }
    if (b == true) {
      a[c] = i;
      c++;
    }
  }

  cout << a[k - 1] << endl;

  return 0;
}