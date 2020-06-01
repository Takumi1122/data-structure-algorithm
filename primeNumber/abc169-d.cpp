#include <bits/stdc++.h>
using namespace std;

// 素因数分解
vector<pair<long long, long long> > prime_factorize(long long n) {
  vector<pair<long long, long long> > res;
  for (long long p = 2; p * p <= n; ++p) {
    if (n % p != 0) continue;
    int num = 0;
    while (n % p == 0) {
      ++num;
      n /= p;
    }
    res.push_back(make_pair(p, num));
  }
  if (n != 1) res.push_back(make_pair(n, 1));
  return res;
}

int main() {
  long long N;
  cin >> N;
  auto pf = prime_factorize(N);
  long long res = 0;
  for (auto p : pf) {
    long long e = p.second;
    long long tmp = 0, cur = 1;
    while (e >= cur) e -= cur++, ++tmp;
    res += tmp;
  }
  cout << res << endl;
}