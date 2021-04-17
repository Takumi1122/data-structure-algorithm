#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 順列全探索

/*
    参考リンク
    ABC 198 D - Send More Money
      https://atcoder.jp/contests/abc198/tasks/abc198_d
*/

int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  set<char> st;
  set<char> first;
  rep(i, s1.size()) st.insert(s1[i]);
  rep(i, s2.size()) st.insert(s2[i]);
  rep(i, s3.size()) st.insert(s3[i]);
  first.insert(s1[0]);
  first.insert(s2[0]);
  first.insert(s3[0]);

  if (st.size() > 10) {
    cout << "UNSOLVABLE" << endl;
    return 0;
  }

  vector<int> a;
  rep(i, 10) a.push_back(i);
  do {
    map<char, char> mp;
    int j = 0;
    bool ok = true;
    for (auto c : st) {
      if (first.count(c) && a[j] == 0) {
        ok = false;
        break;
      }
      mp[c] = '0' + a[j];
      j++;
    }
    if (!ok) continue;
    string n1, n2, n3;
    rep(i, s1.size()) n1 += mp[s1[i]];
    rep(i, s2.size()) n2 += mp[s2[i]];
    rep(i, s3.size()) n3 += mp[s3[i]];
    ll n11 = stoll(n1);
    ll n22 = stoll(n2);
    ll n33 = stoll(n3);
    if (n11 + n22 == n33) {
      cout << n11 << endl;
      cout << n22 << endl;
      cout << n33 << endl;
      return 0;
    }
  } while (next_permutation(a.begin(), a.end()));
  cout << "UNSOLVABLE" << endl;
  return 0;
}