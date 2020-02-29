#include <iostream>
#include <vector>
using namespace std;

struct Heap {
  vector<int> heap;
  Heap() {}

  /* ヒープに値 v を挿入 */
  void push(int v) {
    heap.push_back(v);             // 最後尾に値追加
    int i = (int)heap.size() - 1;  // 追加されたノード番号
    while (i > 0) {
      int p = (i - 1) / 2;      // 親のノード番号
      if (heap[p] >= v) break;  // 逆転なかったら終わり
      heap[i] = heap[p];        // 自分のノードを親の値に
      i = p;                    // 自分は上に行く
    }
    heap[i] = v;  // v は最終的にはこの位置に
  }

  /* 最大値を知る */
  int top() {
    if (!heap.empty())
      return heap[0];
    else
      return -1;
  }

  /* 最大値を削除 */
  void pop() {
    if (heap.empty()) return;
    int v = heap.back();  // ノードに持ってくる値
    heap.pop_back();
    int i = 0;  // 根から降ろしていく
    while (i * 2 + 1 < (int)heap.size()) {
      // 子供同士を比較して大きい方を child1 とする
      int child1 = i * 2 + 1, child2 = i * 2 + 2;
      if (child2 < (int)heap.size() && heap[child2] > heap[child1])
        child1 = child2;
      if (heap[child1] <= v) break;  // 逆転なかったら終わり
      heap[i] = heap[child1];        // 自分のノードを子供の値に
      i = child1;                    // 自分は下に行く
    }
    heap[i] = v;  // v は最終的にはこの位置に
  }
};