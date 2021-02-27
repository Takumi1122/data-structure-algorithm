#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  ll n;
  cin >> n;
  set<ll> st;
  for (ll i = 2; i * i <= n; i++) {
    ll a = i * i;
    while (a <= n) {
      st.insert(a);
      a *= i;
    }
  }

  cout << n - st.size() << endl;
  return 0;
}