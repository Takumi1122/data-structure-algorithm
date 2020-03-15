#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  
  ll c = N / (A+B);
  ll d = N % (A+B);
  if (d >= A) {
    cout << (A * c + A) << endl;
  } else {
    cout << (A * c + d) << endl;
  }

  return 0;
}