#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using namespace std;

// 括弧列の整合性チェック (スタック)

bool check(const string &S) {
  stack<int> st;               // 左括弧の index を格納するスタック
  vector<pair<int, int> > ps;  // 対応を表すペア

  // ループを回す
  rep(i, S.size()) {
    if (S[i] == '(')
      st.push(i);
    else {
      if (st.empty()) {
        cout << "error" << endl;
        return false;
      }
      int t = st.top();
      st.pop();
      ps.push_back({t, i});
    }
  }

  // スタックが空でなかったら左括弧が過剰
  if (!st.empty()) {
    cout << "too many (" << endl;
    return false;
  }

  // 整合を出力
  sort(ps.begin(), ps.end());
  rep(i, ps.size()) {
    if (i) cout << ", ";
    cout << "(" << ps[i].first << ", " << ps[i].second << ")";
  }
  cout << endl;
  return true;
}

int main() {
  check("((()())())");  // (0, 9) (1, 6), (2, 3), (4, 5), (7, 8)
  check("())");         // error
  check("(()");         // too many (
}