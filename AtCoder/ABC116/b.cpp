#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int s;
  cin >> s;

  int a = s;
  map<int, int> mp;
  mp[s]++;
  int ans = 0;
  for (int i = 2; i <= 1000000; i++) {
    if (a % 2 == 0) {
      a /= 2;
    } else {
      a = 3 * a + 1;
    }
    mp[a]++;
    if (mp[a] > 1) {
      ans = i;
      cout << ans << endl;
      return 0;
    }
  }
  return 0;
}