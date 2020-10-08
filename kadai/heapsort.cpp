#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>

const int max_length = 65536;
int size = 0;
int data[max_length];

//�v�findex�ɑ΂���e�v�f�̃C���f�b�N�X
int parent(int index) {
	return std::floor((index - 1) / 2);
}

//�v�findex�ɑ΂��鍶�m�[�h�̃C���f�b�N�X
int left(int index) {
	return 2 * index + 1;
}

//�v�findex�ɑ΂���E�m�[�h�̃C���f�b�N�X
int right(int index) {
	return 2 * index + 2;
}

//�v�f�̑}��
void insert(int value) {
	if (size < max_length) {
		data[size++] = value;
	}
}

//�e�m�[�h�ɑ΂��ăq�[�v�����̕ێ����s���֐�
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

//�ؑS�̂ɑ΂��ăq�[�v�����̕ێ����s���֐�
void build_heap() {
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(i);
	}
}

//�q�[�v�\�[�g���s���֐�
void heap_sort(int n) {
  // �S�̂��q�[�v�ɂ���
  build_heap();

  // �q�[�v����1��1�ő�l��pop����
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