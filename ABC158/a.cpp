#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int c;
  string S;
  cin >> S;

  rep(i, 3) {
    if(S[i] == 'A') ++c;
  } 

  if(c == 3 || c == 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

  return 0;
}