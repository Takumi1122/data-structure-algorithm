#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  int cnt1 = 0;
  int cnt2 = 0;
  rep(i, m) {
    int a;
    cin >> a;
    if (a >= x) {
      cnt1++;
    } else {
      cnt2++;
    }
  }

  cout << min(cnt1, cnt2) << endl;
  return 0;
}