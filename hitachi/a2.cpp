#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  string hitachi = "";
  for (int i = 1; i <= 5; i++) {
    hitachi += "hi";
    if (hitachi == s) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}