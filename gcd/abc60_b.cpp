#include <iostream>
using namespace std;

long long GCD(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return GCD(b, a % b);
}

int main() {
  long long A, B, C;
  cin >> A >> B >> C;
  if (C % GCD(A, B) == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}