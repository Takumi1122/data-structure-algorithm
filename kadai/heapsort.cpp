#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>

const int max_length = 65536;
int size = 0;
int data[max_length];

//要素indexに対する親要素のインデックス
int parent(int index) {
	return std::floor((index - 1) / 2);
}

//要素indexに対する左ノードのインデックス
int left(int index) {
	return 2 * index + 1;
}

//要素indexに対する右ノードのインデックス
int right(int index) {
	return 2 * index + 2;
}

//要素の挿入
void insert(int value) {
	if (size < max_length) {
		data[size++] = value;
	}
}

//各ノードに対してヒープ条件の保持を行う関数
void heapify(int index) {
  int l, r, largest;
  l = left(index);
  r = right(index);

  if (l < size && data[l] > data[index])
    largest = l;
  else
    largest = index;
  if (r < size && data[r] > data[largest]) largest = r;

  if (largest != index) {
    std::swap(data[index], data[largest]);
    heapify(largest);
  }
}

//木全体に対してヒープ条件の保持を行う関数
void build_heap() {
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(i);
	}
}

//ヒープソートを行う関数
void heap_sort(int n) {
  // 全体をヒープにする
  build_heap();

  // ヒープから1個1個最大値をpopする
  for (int i = n - 1; i > 0; i--) {
    std::swap(data[0], data[i]);
		size--;
    heapify(0);
  }
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int value;
		std::cin >> value;
		insert(value);
	}

	heap_sort(n);

	for (int i = 0; i < n; i++) {
		std::cout << data[i] << ", ";
	}
	return 0;
}