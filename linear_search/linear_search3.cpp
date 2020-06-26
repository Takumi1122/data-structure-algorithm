#include <iostream>
using namespace std;

int n;
int a[11000];  // 最大 10000 個なので余裕を持って 11000 に

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  int findID = -1;  // ここに見つかった場所を格納します
                    // (実はこれ自体がフラグの役割を果たします)
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {  // 見つかったら、
      findID = i;     // 場所を記録して、
      break;          // break
    }
  }

  if (findID != -1)
    cout << findID << endl;
  else
    cout << "No" << endl;
}