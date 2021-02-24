#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<int> cnt(100100);
  rep(i, n) {
    int a;
    cin >> a;
    cnt[a]++;
  }

  int ans = 0;
  rep(i, 100100) {
    int sum = 0;
    if (i == 0) {
      sum += cnt[i];
      sum += cnt[i + 1];
    } else {
      sum += cnt[i - 1];
      sum += cnt[i];
      sum += cnt[i + 1];
    }
    ans = max(ans, sum);
  }

  cout << ans << endl;
  return 0;
}