#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  map<string, int> a;
  a["SUN"] = 7;
  a["MON"] = 6;
  a["TUE"] = 5;
  a["WED"] = 4;
  a["THU"] = 3;
  a["FRI"] = 2;
  a["SAT"] = 1;
  string s;
  cin >> s;
  cout << a[s] << endl;
  return 0;
}