#include <iostream>
using namespace std;

const int INF = 10000000;  // 十分大きな値に

int N;
int A[210];  // 最大 200 個なので余裕を持って 210 に

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  int res = INF;

  for (int i = 0; i < N; i++) {
    int count = 0;  // 何回 2 で割れるか

    while (A[i] % 2 == 0) {
      A[i] /= 2;
      count++;
    }

    // 最小値を更新
    if (res > count) res = count;
  }

  cout << res << endl;
}