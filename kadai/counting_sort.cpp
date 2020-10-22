#include <iostream>

//カウンティングソートを行う関数
//配列は0オリジンであることに注意
void counting_sort(int src[], int dest[], int temp[], int n, int k) {
  for (int i = 0; i < k; i++) temp[i] = 0;

  for (int i = 0; i < n; i++) temp[src[i]]++;
  // temp[i] は i に等しい要素の個数を含む

  for (int i = 1; i < k; i++) temp[i] = temp[i] + temp[i - 1];
  // temp[i] は i 以下の要素の個数を含む

  for (int i = n - 1; i >= 0; i--) dest[--temp[src[i]]] = src[i];
}

int main() {
  int n;  // ソート列の個数
  int k;  // 数値の範囲(0～k-1)

  //データ入力
  std::cin >> n;
  std::cin >> k;

  int* src = new int[n];   // ソートを行う入力配列
  int* dest = new int[n];  // ソートされた配列
  int* temp = new int[k];  // 補助的な配列

  for (int i = 0; i < n; i++) {
    std::cin >> src[i];
  }

  //ソート
  counting_sort(src, dest, temp, n, k);

  //データ出力
  for (int i = 0; i < n; i++) {
    std::cout << dest[i] << ", ";
  }
  delete[] src;
  delete[] dest;
  delete[] temp;
  return 0;
}