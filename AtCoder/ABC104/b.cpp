#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  string s;
  cin >> s;

  bool ok = true;
  if (s[0] != 'A') ok = false;

  map<char, int> mp;
  for (int i = 2; i < s.size() - 1; i++) {
    mp[s[i]]++;
  }
  if (mp['C'] != 1) ok = false;

  for (int i = 1; i < s.size(); i++) {
    if (i != s.size() - 1) {
      if (isupper(s[i]) && s[i] != 'C') ok = false;
    } else {
      if (isupper(s[i])) ok = false;
    }
  }

  if (ok) {
    cout << "AC" << endl;
  } else {
    cout << "WA" << endl;
  }
  return 0;
}