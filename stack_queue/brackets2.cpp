#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using namespace std;

bool check(const string &S) {
  int top = 0;
  for (auto c : S) {
    if (c == '(')
      ++top;
    else {
      if (top == 0) return false;
      --top;
    }
  }
  if (top)
    return false;
  else
    return true;
}

int main() {
  cout << check("((()())())") << endl;  // true
  cout << check("())") << endl;         // false
  cout << check("(()") << endl;         // false
}