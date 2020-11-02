#include <iostream>
using namespace std;

//スタックの実装
class STACK {
 public:
  int top = 0;  // 最後に挿入された要素の格納場所(=要素数)
  const int MAX = 100;    // スタックに格納できる数
  int *S = new int[MAX];  // 要素を格納するサイズMAXの配列

  void PUSH(int x) {
    // ここを埋める
    if (top == MAX) {
      cout << "オーバーフロー";
      exit(1);
    }
    S[top] = x;
    top = top + 1;
  }

  int POP() {
    // ここを埋める
    if (STACK_EMPTY()) {
      cout << "アンダーフロー";
      exit(1);
    }
    top = top - 1;
    return S[top];
  }

  bool STACK_EMPTY() {
    // ここを埋める
    if (top == 0)
      return 1;
    else
      return 0;
  }
};

//キューの実装
class QUEUE {
 public:
  int head = 0;           // キューの先頭の位置
  int tail = 0;           // 次に追加される位置
  const int MAX = 100;    // キューに格納できる数
  int *Q = new int[MAX];  // 要素を格納するサイズMAXの配列
  bool full = false;  // キューに全て格納されているかを返す変数

  void ENQUEUE(int x) {
    // ここを埋める
    Q[tail++] = x;
    if (tail == MAX) tail = 0;
  }

  int DEQUEUE() {
    // ここを埋める
    int x = Q[head];
    ++head;
    if (head == MAX) head = 0;
    return x;
  }
};

int main() {
  //スタックのテスト
  STACK stack;
  stack.PUSH(1);
  stack.PUSH(2);
  stack.PUSH(3);
  std::cout << stack.POP() << std::endl;
  stack.PUSH(4);
  stack.PUSH(5);
  std::cout << stack.POP() << std::endl;
  std::cout << stack.POP() << std::endl;
  stack.PUSH(6);
  stack.PUSH(7);
  stack.PUSH(8);
  stack.PUSH(9);
  stack.PUSH(10);
  stack.PUSH(11);
  stack.PUSH(12);
  std::cout << stack.POP() << std::endl;
  std::cout << stack.POP() << std::endl;
  std::cout << stack.POP() << std::endl;
  std::cout << stack.POP() << std::endl;
  std::cout << stack.POP() << std::endl;
  std::cout << stack.POP() << std::endl;
  std::cout << stack.POP() << std::endl;
  std::cout << stack.POP() << std::endl;
  std::cout << stack.POP() << std::endl;

  //キューのテスト
  QUEUE queue;
  queue.ENQUEUE(1);
  queue.ENQUEUE(2);
  std::cout << queue.DEQUEUE() << std::endl;
  queue.ENQUEUE(3);
  queue.ENQUEUE(4);
  queue.ENQUEUE(5);
  queue.ENQUEUE(6);
  std::cout << queue.DEQUEUE() << std::endl;
  std::cout << queue.DEQUEUE() << std::endl;
  std::cout << queue.DEQUEUE() << std::endl;
  queue.ENQUEUE(7);
  queue.ENQUEUE(8);
  queue.ENQUEUE(9);
  queue.ENQUEUE(10);
  std::cout << queue.DEQUEUE() << std::endl;
  queue.ENQUEUE(11);
  queue.ENQUEUE(12);
  queue.ENQUEUE(13);
  queue.ENQUEUE(14);
  std::cout << queue.DEQUEUE() << std::endl;
  std::cout << queue.DEQUEUE() << std::endl;
  std::cout << queue.DEQUEUE() << std::endl;
  std::cout << queue.DEQUEUE() << std::endl;
  std::cout << queue.DEQUEUE() << std::endl;
  std::cout << queue.DEQUEUE() << std::endl;
  std::cout << queue.DEQUEUE() << std::endl;
  std::cout << queue.DEQUEUE() << std::endl;
  std::cout << queue.DEQUEUE() << std::endl;

  return 0;
}
