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
  long long N;
  cin >> N;

  const int MOD = 1000000007;
  vector<long long> ex(N + 1, 0);  // exp[p] := p の指数
  for (long long n = 2; n <= N; ++n) {
    const auto &res = prime_factorize(n);  // n の素因数分解
    for (auto p : res) ex[p.first] += p.second;
  }
  long long res = 1;
  for (int p = 2; p <= N; ++p) {
    res *= ex[p] + 1;  // 約数の個数は (exp + 1) の積
    res %= MOD;
  }
  cout << res << endl;
}