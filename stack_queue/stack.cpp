#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 100000;  // スタック配列の最大サイズ

int st[MAX];  // スタックを表す配列
int top = 0;  // スタックの先頭を表すポインタ

// スタックを初期化する
void init() {
  top = 0;  // スタックポインタを初期位置に
}

// スタックが空かどうかを判定する
bool isEmpty() {
  return (top == 0);  // スタックサイズが 0 かどうか
}

// スタックが満杯かどうかを判定する
bool isFull() {
  return (top == MAX);  // スタックサイズが MAX かどうか
}

// push (top を進めて要素を格納)
void push(int v) {
  if (isFull()) {
    cout << "error: stack is full." << endl;
    return;
  }
  st[top++] = v;  // st[top] = v; と top++; をまとめてこのように表せます
}

// pop (top をデクリメントして、top の位置にある要素を返す)
int pop() {
  if (isEmpty()) {
    cout << "error: stack is empty." << endl;
    return -1;
  }
  return st[--top];  // --top; と return st[top]; をまとめてこのように表せます
}

int main() {
  init();  // スタックを初期化

  push(3);  // スタックに 3 を積む {} -> {3}
  push(5);  // スタックに 5 を積む {3} -> {3, 5}
  push(7);  // スタックに 7 を積む {3, 5} -> {3, 5, 7}

  cout << pop() << endl;  // {3, 5, 7} -> {3, 5} で 7 を出力
  cout << pop() << endl;  // {3, 5} -> {3} で 5 を出力

  push(9);   // 新たに 9 を積む {3} -> {3, 9}
  push(11);  // {3, 9} -> {3, 9, 11}

  pop();  // {3, 9, 11} -> {3, 9}
  pop();  // {3, 9} -> {3}
  pop();  // {3} -> {}

  // 空かどうかを check: empty の方を出力
  cout << (isEmpty() ? "empty" : "not empty") << endl;
}