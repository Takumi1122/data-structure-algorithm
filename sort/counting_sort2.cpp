#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;  // 配列の値は 100000 未満だとします

int main() {
  int n;  // 要素数
  cin >> n;
  vector<int> a(n);  // 整列したい配列ベクトル (サイズ を n に初期化)
  for (int i = 0; i < n; i++) {
    cin >> a[i];  // 整列したい配列を取得
  }

  /* 各要素の個数をカウントします */
  /* num[v] := v の個数 */
  int num[MAX] = {0};
  for (int i = 0; i < n; i++) {
    ++num[a[i]];  // a[i] をカウントします
  }

  /* ソート済み配列 */
  vector<int> sorted;
  for (int v = 1; v < MAX; v++) {       // 各キー値 v に対して
    for (int i = 0; i < num[v]; i++) {  // その個数分並べる
      sorted.push_back(v);
    }
  }

  for (int i = 0; i < (int)sorted.size(); i++) cout << sorted[i] << " ";
  cout << endl;

  return 0;
}