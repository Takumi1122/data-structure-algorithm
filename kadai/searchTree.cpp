#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//木の実装

const int max_length = 65536;
int size = 0;
int data[max_length];

//要素indexに対する親要素のインデックス
int parent(int index) { return std::floor((index - 1) / 2); }

//要素indexに対する左ノードのインデックス
int left(int index) { return 2 * index + 1; }

//要素indexに対する右ノードのインデックス
int right(int index) { return 2 * index + 2; }

//要素の挿入
void insert(int value) {
  if (size < max_length) {
    data[size++] = value;
  }
}

//探索アルゴリズム
//今回の木構造は配列なので配列を走査すれば探索できるが、
//木構造が常に配列で実装されている保証は無いため講義資料にあるやり方で探索をしてみること

//値としてvalueを持つノードを深さ優先探索し,
//そのノードの配列dataにおけるインデックスを返す関数
//見つからなかった場合は-1などを返すこと
int depth_first_search(int value) {
  //ここを埋める
  stack<int> st;
  st.push(0);
  while (!st.empty()) {
    int v = st.top();
    st.pop();
    if (v >= size) continue;
    if (data[v] == value) return v;
    int l = left(v);
    int r = right(v);
    st.push(l);
    st.push(r);
  }
  return -1;
}

//値としてvalueを持つノードを幅優先探索し,
//そのノードの配列dataにおけるインデックスを返す関数
//見つからなかった場合は-1などを返すこと
int breadth_first_search(int value) {
  //ここを埋める
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    if (v >= size) break;
    if (data[v] == value) return v;
    int l = left(v);
    int r = right(v);
    que.push(l);
    que.push(r);
  }
  return -1;
}

int main() {
  //データ入力
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int data;
    std::cin >> data;
    insert(data);
  }

  //探索する数の入力
  int target;
  std::cin >> target;

  //深さ優先探索
  std::cout << depth_first_search(target) << std::endl;

  //幅優先探索
  std::cout << breadth_first_search(target) << std::endl;

  return 0;
}