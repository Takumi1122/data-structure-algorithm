#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, k;
  cin >> a >> b >> k;

  set<int> st;
  for (int i = a; i <= min(b, a + k - 1); i++) st.insert(i);
  for (int i = b; i >= max(a, b - k + 1); i--) st.insert(i);

  for (auto ans : st) cout << ans << endl;
  return 0;
}