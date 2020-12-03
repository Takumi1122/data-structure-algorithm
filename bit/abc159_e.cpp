#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 159 E - Dividing Chocolate
      https://atcoder.jp/contests/abc159/tasks/abc159_e
*/

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> fi(h);
  rep(i, h) cin >> fi[i];

  int ans = 1 << 29;
  for (int bit = 0; bit < (1 << (h - 1)); ++bit) {
    // 縦の区切り方がOKか
    bool ok_h = true;
    int n = 0;
    vector<int> ord(h, 0);
    rep(i, h - 1) {
      if (!(bit & (1 << i)))
        ord[i + 1] = ord[i];
      else
        ord[i + 1] = ord[i] + 1, ++n;
    }

    int add = 0;
    vector<int> nums(n + 1, 0);
    rep(i, w) {
      // 縦方向にあるホワイトチョコレートマス(1)の数
      vector<int> one(n + 1, 0);
      bool ok_w = true;
      rep(j, h) {
        one[ord[j]] += fi[j][i] - '0';
        // 縦の区切り方がNG
        if (one[ord[j]] > k) ok_h = false;

        nums[ord[j]] += fi[j][i] - '0';
        //　ホワイトチョコレートマス(1)の数がkを超える
        if (nums[ord[j]] > k) ok_w = false;
      }
      // 限界を超える手前でラインを引く
      if (!ok_w) ++add, nums = one;
    }
    if (ok_h) chmin(ans, n + add);
  }

  cout << ans << endl;
  return 0;
}