#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<string> w(n);
  rep(i, n) cin >> w[i];

  bool ok = true;
  set<string> st;
  rep(i, n) {
    if (i == 0) {
      st.insert(w[i]);
    } else {
      if (w[i - 1][w[i - 1].size() - 1] != w[i][0]) ok = false;
      if (st.count(w[i])) ok = false;
      st.insert(w[i]);
    }
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}