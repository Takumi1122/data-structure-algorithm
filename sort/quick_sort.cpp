#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// クイックソート o(n^2) 安定ソート×　内部ソート○

/* 配列 a の [left, right) をソートします */
void quickSort(vector<int> &a, int left, int right) {
  if (right - left <= 1) return;

  int pivot_index = (left + right) / 2;  // 適当にここでは中点とします
  int pivot = a[pivot_index];
  swap(a[pivot_index], a[right - 1]);  // pivot と右端を swap

  int i = left;                             // iterator
  for (int j = left; j < right - 1; j++) {  // j は全体を眺めて
    if (a[j] < pivot) {  // pivot 未満のがあったら左に詰めていく
      swap(a[i++], a[j]);
    }
  }
  swap(a[i], a[right - 1]);  // pivot を適切な場所に挿入

  /* 再帰的に解く */
  quickSort(a, left, i);       // 左半分 (pivot 未満)
  quickSort(a, i + 1, right);  // 右半分 (pivot 以上)
}

int main() {
  int n;  // 要素数
  cin >> n;
  vector<int> a(n);  // 整列したい配列ベクトル (サイズ を n に初期化)
  rep(i, n) {
    cin >> a[i];  // 整列したい配列を取得
  }

  /* クイックソート */
  quickSort(a, 0, n);

  rep(i, n) cout << a[i] << " ";
  cout << endl;

  return 0;
}