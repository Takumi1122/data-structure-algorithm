#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  ll n;
  cin >> n;

  ll cnt = 0;
  ll n1 = n;
  while (n1 >= 1000) {
    n1 /= 1000;
    cnt++;
  }

  ll ans = 0;
  for (int i = 1; i <= cnt; i++) {
    string s = "";
    int j = i;
    while (j) {
      j--;
      s += "999";
    }
    ll a = stoll(s);
    ans += n - a;
  }

  cout << ans << endl;
  return 0;
}