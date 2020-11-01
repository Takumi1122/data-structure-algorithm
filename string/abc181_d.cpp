#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 181 D - Hachi
      https://atcoder.jp/contests/abc181/tasks/abc181_d
*/

int main() {
  string s;
  cin >> s;

  if (s.size() == 1) {
    if (stoi(s) % 8 == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  if (s.size() == 2) {
    if (stoi(s) % 8 == 0) {
      cout << "Yes" << endl;
      return 0;
    }
    swap(s[0], s[1]);
    if (stoi(s) % 8 == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  vector<int> cnt(10);
  for (char x : s) cnt[x - '0']++;

  for (int i = 104; i < 1000; i += 8) {
    string s_sub = to_string(i);
    vector<int> cnt_sub(10);
    int num = 0;

    for (char x : s_sub) cnt_sub[x - '0']++;
    for (char x : s_sub) {
      if (cnt_sub[x - '0'] <= cnt[x - '0']) {
        num++;
      }
    }

    if (num == 3) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}