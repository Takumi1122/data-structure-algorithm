#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  char win[222][222];
  win['R']['R'] = win['R']['S'] = win['S']['R'] = 'R';
  win['S']['S'] = win['S']['P'] = win['P']['S'] = 'S';
  win['P']['P'] = win['P']['R'] = win['R']['P'] = 'P';

  int n, k;
  string s;
  cin >> n >> k >> s;

  while (k--) {
    string t = s + s;
    rep(i, n) s[i] = win[t[i * 2]][t[i * 2 + 1]];
  }

  cout << s[0] << endl;
  return 0;
}