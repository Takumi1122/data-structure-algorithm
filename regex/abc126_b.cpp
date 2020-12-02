#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 126 B - YYMM or MMYY
      https://atcoder.jp/contests/abc126/tasks/abc126_b
*/

int main() {
  string s;
  cin >> s;

  smatch smatch;
  if (regex_search(s, smatch, regex("^(0[1-9]|1[0-2])[0-9]{2}")) &&
      regex_search(s, smatch, regex("^[0-9]{2}(0[1-9]|1[0-2])"))) {
    cout << "AMBIGUOUS" << endl;
  } else if (regex_search(s, smatch, regex("^(0[1-9]|1[0-2])[0-9]{2}"))) {
    cout << "MMYY" << endl;
  } else if (regex_search(s, smatch, regex("^[0-9]{2}(0[1-9]|1[0-2])"))) {
    cout << "YYMM" << endl;
  } else {
    cout << "NA" << endl;
  }
  return 0;
}