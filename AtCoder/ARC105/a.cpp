#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  vector<int> a(4);
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  ll sum_no = 0;
  rep(i, 4) sum_no += a[i];

  bool exist = false;
  for (int bit = 0; bit < (1 << 4); ++bit) {
    ll sum = 0;
    rep(i, 4) {
      if (bit & (1 << i)) {
        sum += a[i];
      }
    }

    ll sum_no1 = sum_no - sum;
    if (sum == sum_no1) exist = true;
  }

  if (exist)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}