#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> ans(n + 1, 0);
  int ac = 0, wa = 0;
  rep(i, m) {
    int num;
    string s;
    cin >> num >> s;
    if (s == "AC" && ans[num] == 0) {
      ans[num]++;
      ac++;
    } else if (s == "WA" && ans[num] == 0) {
      wa++;
    } else {
      continue;
    }
  }
  printf("%d %d\n", ac, wa);
  return 0;
}