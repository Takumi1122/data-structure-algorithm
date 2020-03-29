#include <iostream>
using namespace std;

long long GCD(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return GCD(b, a % b);
}

int main() {
  long long ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  cout << GCD(abs(ax - bx), abs(ay - by)) - 1 << endl;
}