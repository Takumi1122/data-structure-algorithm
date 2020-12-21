#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 3重のbit全探索

/*
    参考リンク
    ABC 119 C - Synthetic Kadomatsu
      https://atcoder.jp/contests/abc119/tasks/abc119_c
*/

int main() {
  int n;
  cin >> n;
  vector<int> a(3);
  vector<int> l(n);
  rep(i, 3) cin >> a[i];
  rep(i, n) cin >> l[i];

  int ans = 1e9;
  vector<int> bit(3);
  for (bit[0] = 1; bit[0] < (1 << n); ++bit[0]) {
    for (bit[1] = 1; bit[1] < (1 << n); ++bit[1]) {
      // 共通要素あったらダメ
      if (bit[1] & bit[0]) continue;
      for (bit[2] = 1; bit[2] < (1 << n); ++bit[2]) {
        // 共通要素があったらダメ
        if (bit[2] & bit[0]) continue;
        if (bit[2] & bit[1]) continue;

        // sums: A〜Cに選んだ竹の長さの合計
        // nums: A〜Cに選んだ竹の本数
        vector<int> sums(3, 0), nums(3, 0);
        rep(i, n) rep(j, 3) {
          if (bit[j] & (1 << i)) {
            sums[j] += l[i];
            nums[j]++;
          }
        }

        // score を求める
        int score = 0;
        rep(i, 3) {
          score += abs(sums[i] - a[i]);  // +1, -1 のコスト
          score += (nums[i] - 1) * 10;   // 合体のコスト
        }
        ans = min(ans, score);
      }
    }
  }

  cout << ans << endl;
  return 0;
}