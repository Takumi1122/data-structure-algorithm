#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 120 C - Unification
      https://atcoder.jp/contests/abc120/tasks/abc120_c
*/

int main() {
  string s;
  cin >> s;
  int n = s.size();

  stack<char> st;
  int ans = 0;
  rep(i, n) {
    st.push(s[i]);
    if (st.size() >= 2) {
      char c1 = st.top();
      st.pop();
      char c2 = st.top();
      st.pop();
      if (c1 == '1' && c2 == '0' || c1 == '0' && c2 == '1') {
        ans += 2;
      } else {
        st.push(c2);
        st.push(c1);
      }
    }
  }

  cout << ans << endl;
  return 0;
}