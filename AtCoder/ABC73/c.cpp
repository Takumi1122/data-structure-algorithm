#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  set<int> st;
  rep(i, n) {
    int a;
    cin >> a;
    if (st.count(a)) {
      st.erase(a);
    } else {
      st.insert(a);
    }
  }
  cout << st.size() << endl;
  return 0;
}