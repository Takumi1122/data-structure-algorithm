#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> ac(n), pena(n);
  rep(i, m) {
    int p;
    string s;
    cin >> p >> s;
    --p;
    if (ac[p]) continue;
    if (s == "AC") {
      ac[p] = 1;
    } else {
      pena[p]++;
    }
  }
  int AC = 0, PENA = 0;
  rep(i, n) {
    AC += ac[i];
    if (ac[i]) PENA += pena[i];
  }
  printf("%d %d\n", AC, PENA);
  return 0;
}
