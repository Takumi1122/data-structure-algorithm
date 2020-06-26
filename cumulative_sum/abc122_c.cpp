#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, q;
  cin >> n >> q;
  string str;
  cin >> str;

  // 累積和
  vector<int> s(n + 1, 0);
  rep(i, n) {
    if (i + 1 < n && str[i] == 'A' && str[i + 1] == 'C')
      s[i + 1] = s[i] + 1;
    else
      s[i + 1] = s[i];
  }

  // クエリ
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    --l, --r;  // 0-indexed にする
    cout << s[r] - s[l] << endl;
  }
}