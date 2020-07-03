#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 100000;  // キュー配列の最大サイズ

int qu[MAX];             // キューを表す配列
int tail = 0, head = 0;  // キューの要素区間を表す変数

// キューを初期化する
void init() { head = tail = 0; }

// キューが空かどうかを判定する
bool isEmpty() { return (head == tail); }

// スタックが満杯かどうかを判定する
bool isFull() { return (head == (tail + 1) % MAX); }

// enqueue (tail に要素を格納してインクリメント)
void enqueue(int v) {
  if (isFull()) {
    cout << "error: queue is full." << endl;
    return;
  }
  qu[tail++] = v;
  if (tail == MAX) tail = 0;  // リングバッファの終端に来たら 0 に
}

// dequeue (head にある要素を返して head をインクリメント)
int dequeue() {
  if (isEmpty()) {
    cout << "error: stack is empty." << endl;
    return -1;
  }
  int res = qu[head];
  ++head;
  if (head == MAX) head = 0;
  return res;
}

int main() {
  init();  // キューを初期化

  enqueue(3);  // キューに 3 を積む {} -> {3}
  enqueue(5);  // キューに 5 を積む {3} -> {3, 5}
  enqueue(7);  // キューに 7 を積む {3, 5} -> {3, 5, 7}

  cout << dequeue() << endl;  // {3, 5, 7} -> {5, 7} で 3 を出力
  cout << dequeue() << endl;  // {5, 7} -> {7} で 5 を出力

  enqueue(9);   // 新たに 9 を積む {7} -> {7, 9}
  enqueue(11);  // {7, 9} -> {7, 9, 11}

  dequeue();  // {7, 9, 11} -> {9, 11}
  dequeue();  // {9, 11} -> {11}
  dequeue();  // {11} -> {}

  // 空かどうかを check: empty の方を出力
  cout << (isEmpty() ? "empty" : "not empty") << endl;
}