#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    HackerRank Misère Nim
      https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/misere-nim
*/

int main() {
  int T;
  cin >> T;
  vector<bool> first_win(T);
  rep(t, T) {
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n) { cin >> s[i]; }

    bool overone = false;  // 1より大きいものが存在するか
    int xor_sum = 0;
    rep(i, n) {
      if (s[i] > 1) overone = true;
      xor_sum ^= s[i];
    }
    if ((overone && xor_sum == 0) || (!overone && xor_sum == 1)) {
      first_win[t] = false;
    } else {
      first_win[t] = true;
    }
  }

  rep(t, T) {
    if (first_win[t]) {
      cout << "First" << endl;
    } else {
      cout << "Second" << endl;
    }
  }
}
