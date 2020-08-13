#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  if (s == "Sunny") cout << "Cloudy" << endl;
  if (s == "Cloudy") cout << "Rainy" << endl;
  if (s == "Rainy") cout << "Sunny" << endl;
  return 0;
}