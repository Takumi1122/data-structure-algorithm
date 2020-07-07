#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  map<string, int> cnt;
  rep(i, n) { cnt[s[i]]++; }
  printf("AC x %d\n", cnt["AC"]);
  printf("WA x %d\n", cnt["WA"]);
  printf("TLE x %d\n", cnt["TLE"]);
  printf("RE x %d\n", cnt["RE"]);
  return 0;
}