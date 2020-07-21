#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// ヒープソート o(n * log(n)) 安定ソート×　内部ソート○

/* a のうち n 番目までをヒープとして、i
 * 番目のノードについて下と比べて逆転していたら解消する */
void heapify(vector<int> &a, int i, int n) {
  int child1 = i * 2 + 1;   // 左の子供
  if (child1 >= n) return;  // 子供がないときは終了
  if (child1 + 1 < n && a[child1 + 1] > a[child1]) child1++;  // 子供同士を比較
  if (a[child1] <= a[i]) return;  // 逆転がなかったら OK
  swap(a[i], a[child1]);          // swap

  /* 再帰的に */
  heapify(a, child1, n);
}

void heapSort(vector<int> &a) {
  int n = (int)a.size();

  /* a 全体をヒープにするフェーズ */
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(a, i, n);
  }

  /* ヒープから 1 個 1 個最大値を pop するフェーズ */
  for (int i = n - 1; i > 0; i--) {
    swap(a[0], a[i]);  // ヒープの最大値を左詰め
    heapify(a, 0, i);  // ヒープサイズは i に
  }
}

int main() {
  int n;  // 要素数
  cin >> n;
  vector<int> a(n);  // 整列したい配列ベクトル (サイズ を n に初期化)
  rep(i, n) {
    cin >> a[i];  // 整列したい配列を取得
  }

  /* ヒープソート */
  heapSort(a);

  rep(i, n) cout << a[i] << " ";
  cout << endl;

  return 0;
}