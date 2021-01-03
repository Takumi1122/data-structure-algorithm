#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  set<string> st;
  rep(i, n) st.insert(s[i]);

  rep(i, n) {
    if (st.count('!' + s[i])) {
      cout << s[i] << endl;
      return 0;
    }
  }

  cout << "satisfiable" << endl;
  return 0;
}