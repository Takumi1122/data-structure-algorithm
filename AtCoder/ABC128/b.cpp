#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<pair<string, pair<int, int>>> sp(n);
  rep(i, n) {
    string s;
    int p;
    cin >> s >> p;
    sp[i].first = s;
    sp[i].second.first = -p;
    sp[i].second.second = i + 1;
  }

  sort(sp.begin(), sp.end());

  rep(i, n) { cout << sp[i].second.second << endl; }

  return 0;
}