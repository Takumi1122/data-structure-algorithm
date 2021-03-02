#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 64 D - Insertion
      https://atcoder.jp/contests/abc064/tasks/abc064_d
*/

int main() {
  int n;
  string s;
  cin >> n >> s;

  stack<char> st;
  rep(i, n) {
    st.push(s[i]);
    if (st.size() >= 2) {
      char c1 = st.top();
      st.pop();
      char c2 = st.top();
      st.pop();
      if (c1 == ')' && c2 == '(') {
      } else {
        st.push(c2);
        st.push(c1);
      }
    }
  }

  int cnt1 = 0;
  int cnt2 = 0;
  int n1 = st.size();
  rep(i, n1) {
    char c = st.top();
    st.pop();
    if (c == '(') {
      cnt1++;
    } else {
      cnt2++;
    }
  }

  string ans = s;
  string s1 = "";
  string s2 = "";
  rep(i, cnt1) s1 += ')';
  rep(i, cnt2) s2 += '(';

  ans = s2 + ans + s1;

  cout << ans << endl;
  return 0;
}