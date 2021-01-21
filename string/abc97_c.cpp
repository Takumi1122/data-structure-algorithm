#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 辞書順K番目の文字列の長さがKを超えることはない
// s.substr(n, m) n(0-index)番目からm文字切り取る
// mが範囲を超えた場合,n文字目以降の全てを切り取る

/*
    参考リンク
    ABC 97 C - K-th Substring
      https://atcoder.jp/contests/abc097/tasks/arc097_a
*/

int main() {
  string s;
  int k;
  cin >> s >> k;

  set<string> st;
  int n = s.size();
  rep(i, n) {
    for (int j = 1; j <= k; j++) {
      // s.substr(n, m) n(0-index)番目からm文字切り取る
      // mが範囲を超えた場合,n文字目以降の全てを切り取る
      string s1 = s.substr(i, j);
      st.insert(s1);
    }
  }

  string ans;
  for (auto si : st) {
    if (k == 1) {
      ans = si;
      break;
    }
    k--;
  }

  cout << ans << endl;
  return 0;
}