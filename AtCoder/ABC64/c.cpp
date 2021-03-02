#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  rep(i, n) {
    int a;
    cin >> a;
    if (a < 400) {
      mp[0]++;
    } else if (a < 800) {
      mp[1]++;
    } else if (a < 1200) {
      mp[2]++;
    } else if (a < 1600) {
      mp[3]++;
    } else if (a < 2000) {
      mp[4]++;
    } else if (a < 2400) {
      mp[5]++;
    } else if (a < 2800) {
      mp[6]++;
    } else if (a < 3200) {
      mp[7]++;
    } else {
      mp[8]++;
    }
  }

  int cnt = 0;
  rep(i, 8) {
    if (mp.count(i)) cnt++;
  }
  int cnt8 = mp[8];

  int amin;
  if (cnt8 == 0) {
    amin = cnt;
  } else {
    amin = max(1, cnt);
  }

  int amax;
  if (cnt8 == 0) {
    amax = cnt;
  } else {
    amax = cnt + cnt8;
  }

  cout << amin << " " << amax << endl;
  return 0;
}