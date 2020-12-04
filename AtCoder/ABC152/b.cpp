#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  char a, b;
  cin >> a >> b;

  string ab = "";
  string ba = "";
  rep(i, (int)(b - '0')) ab += a;
  rep(i, (int)(a - '0')) ba += b;

  if (a > b) {
    cout << ba << endl;
  } else {
    cout << ab << endl;
  }
  return 0;
}