#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// a < b か？
bool comp(char a, char b) {
  if (a == 'R')
    return (b == 'P');
  else if (a == 'P')
    return (b == 'S');
  else
    return (b == 'R');
}
// a と b のどちらが勝つか？
char which(char a, char b) {
  if (comp(a, b))
    return b;
  else
    return a;
}

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  auto run = [&]() -> void {
    string t = s + s;
    s = "";
    for (int i = 0; i < n * 2; i += 2) s += which(t[i], t[i + 1]);
  };

  rep(i, k) run();
  cout << s[0] << endl;
  return 0;
}