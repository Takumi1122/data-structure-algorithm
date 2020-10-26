#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 蟻本P45: 辞書順最小の問題

int main() {
  int n;
  string s;
  cin >> n >> s;

  int a = 0, b = n - 1;
  string t;

  while (a <= b) {
    // 左から見た場合と右から見た場合を比較
    bool left = false;
    for (int i = 0; i <= b - a; i++) {
      if (s[a + i] < s[b - i]) {
        left = true;
        break;
      } else if (s[a + i] > s[b - i]) {
        left = false;
        break;
      }
    }

    if (left)
      t += s[a++];
    else
      t += s[b--];
  }

  cout << t << endl;
  return 0;
}