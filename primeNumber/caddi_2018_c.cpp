#include <iostream>
#include <vector>
using namespace std;

vector<pair<long long, long long> > prime_factorize(long long N) {
  vector<pair<long long, long long> > res;
  for (long long a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    long long ex = 0;
    while (N % a == 0) {
      ++ex;
      N /= a;
    }
    res.push_back({a, ex});
  }
  if (N != 1) res.push_back({N, 1});
  return res;
}

int main() {
  int N;
  long long P;
  cin >> N >> P;
  const auto &pf = prime_factorize(P);
  long long res = 1;
  for (auto p : pf) {
    for (int j = 0; j < p.second / N; ++j) res *= p.first;
  }
  cout << res << endl;
}