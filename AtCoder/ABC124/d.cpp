#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 操作: flip
// 「連続する0の区間」を間にK個挟む

/*
    参考リンク
    ABC 124 D - Handstand
      https://atcoder.jp/contests/abc124/tasks/abc124_d
*/

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  // 「1の個数」「0の個数」を交互に記録していく
  vector<int> num;
  if (s[0] == '0') num.push_back(0);  // 先頭が0だったら
  for (int i = 0; i < s.size();) {
    int j = i;
    while (j < s.size() && s[j] == s[i]) ++j;  // S[i]の数値がどこまで続くか
    num.push_back(j - i);
    i = j;
  }
  if (s.back() == '0') num.push_back(0);  //最後尾が0だったら

  // 累積和
  vector<int> sum((int)num.size() + 1, 0);
  rep(i, num.size()) sum[i + 1] = sum[i] + num[i];

  // 偶数番目の添字から始まる、長さ2K+1(以下)
  // の区間の総和のうち、最大値を求める
  int ans = 0;
  for (int left = 0; left < sum.size(); left += 2) {
    int right = left + k * 2 + 1;
    if (right >= sum.size()) right = (int)sum.size() - 1;
    ans = max(ans, sum[right] - sum[left]);
  }

  cout << ans << endl;
  return 0;
}