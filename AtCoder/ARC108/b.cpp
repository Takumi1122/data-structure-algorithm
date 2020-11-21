#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ARC 108 B - Abbreviate Fox
      https://atcoder.jp/contests/arc108/tasks/arc108_b
*/

int main() {
  int n;
  string s;
  cin >> n >> s;
  int cnt = 0;
  stack<char> st;
  rep(i, n) {
    st.push(s[i]);
    if (st.size() >= 3) {
      char c1 = st.top();
      st.pop();
      char c2 = st.top();
      st.pop();
      char c3 = st.top();
      st.pop();
      if (c1 == 'x' && c2 == 'o' && c3 == 'f') {
        cnt++;
      } else {
        st.push(c3);
        st.push(c2);
        st.push(c1);
      }
    }
  }
  cout << n - 3 * cnt << endl;
  return 0;
}