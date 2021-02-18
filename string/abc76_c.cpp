#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// set: 集合の中から辞書順最小を取り出す *(ans.begin())

/*
    参考リンク
    ABC 76 C - Dubious Document 2
      https://atcoder.jp/contests/abc076/tasks/abc076_c
*/

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();

  if (n < m) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }

  set<string> ans;

  rep(i, n - m + 1) {
    bool ok = true;
    string s1 = s;
    rep(j, m) {
      if (s1[j + i] != '?' && s1[j + i] != t[j]) ok = false;
    }
    if (ok) {
      rep(j, m) if (s1[j + i] = '?') s1[j + i] = t[j];
      rep(j, n) if (s1[j] == '?') s1[j] = 'a';
      ans.insert(s1);
    }
  }

  if (ans.size() != 0) {
    cout << *(ans.begin()) << endl;
  } else {
    cout << "UNRESTORABLE" << endl;
  }
  return 0;
}