#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<string> st;
ll k;

void dfs(string s, char mx, ll ke) {
  if (s.size() == ke) {
    cout << s << endl;
    st.push_back(s);
    return;
  }
  for (char c = 'a'; c <= mx + 1; c++) {
    string t = s;
    t += c;
    dfs(t, max(mx, c), ke);
  }
}

int main() {
  ll n;
  cin >> n;
  if (n <= 26) {
    char s1 = 'a' + (n - 1);
    cout << s1 << endl;
    return 0;
  }
  ll keta = 0;
  ll n1 = n;
  while (n1 > 0) {
    n1 /= 26;
    keta++;
  }
  n -= pow(26, keta - 1);
  k = keta;
  dfs("", 'a' - 1, keta);
  cout << st[n - 1] << endl;
  return 0;
}