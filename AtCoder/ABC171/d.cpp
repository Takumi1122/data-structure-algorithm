#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, ll> x;
  ll sum = 0;
  rep(i, n) {
    cin >> a[i];
    x[a[i]]++;
    sum += a[i];
  }
  int q;
  cin >> q;
  vector<P> bc(q);
  rep(i, q) {
    ll b, c;
    cin >> b >> c;
    bc[i].first = b;
    bc[i].second = c;
  }
  rep(i, q) {
    ll y = bc[i].second - bc[i].first;
    sum += y * x[bc[i].first];
    cout << sum << endl;
    x[bc[i].second] += x[bc[i].first];
    x[bc[i].first] = 0;
  }
  return 0;
}