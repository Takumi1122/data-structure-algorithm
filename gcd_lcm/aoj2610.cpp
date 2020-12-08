#include <iostream>
using namespace std;

/*
    // レプユニット数
    ・全ての桁が1である整数をレプユニット数と言う
    ・2と5以外の任意の素数pについて、あるレプユニット数Uが存在して、Uはpの倍数となる

    レプユニット数: U = (10^p-1 - 1) / 9

    p≠2,5のときは、10はpの倍数でないので、Fermatの小定理より、
    10^(p-1) - 1 ≡ 0 (mod p)

    さらにp≠3のときは、pと9が互いに素なので、
    (10^(p-1) - 1) / 9 ≡ 0 (mod p)
*/

/*
    参考リンク
    AOJ 2610 Fast Division
      https://onlinejudge.u-aizu.ac.jp/problems/2610
*/

int main() {
  int n;
  cin >> n;
  if (n == 0)
    cout << 1 << endl;
  else if (n == 1)
    cout << 2 << endl;
  else if (n == 2)
    cout << 1 << endl;
  else
    cout << 0 << endl;
}