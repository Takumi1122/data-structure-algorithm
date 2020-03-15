#include <iostream>
#include <vector>
using namespace std;

// 最大公約数を求める
long long GCD(long long x, long long y) { return y ? GCD(y, x % y) : x; }

// 素因数分解
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
  long long A, B;
  cin >> A >> B;

  // 最大公約数を求める
  long long G = GCD(A, B);

  // G を素因数分解して、「素因数の個数 + 1」が答え
  const auto &pf = prime_factorize(G);
  cout << pf.size() + 1 << endl;
}