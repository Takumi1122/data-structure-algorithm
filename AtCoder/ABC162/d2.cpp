#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  long long r = 0, g = 0, b = 0;
  for (auto c : S) {
    if (c == 'R')
      ++r;
    else if (c == 'G')
      ++g;
    else
      ++b;
  }
  long long all = r * g * b;
  long long sub = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (S[i] == S[j]) continue;
      int k = j * 2 - i;
      if (k >= N || S[k] == S[i] || S[k] == S[j]) continue;
      ++sub;
    }
  }
  cout << all - sub << endl;
}