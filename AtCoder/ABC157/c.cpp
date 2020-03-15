#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int N;
int M;
int S[5];
int C[5];
int v = -1;
int count1 = 0;
int count2 = 0;
int count3 = 0;

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> S[i] >> C[i];
  }

  for (int i = 0; i < M; i++) {
    if (S[i] == 1) {
      cout << v << endl;
      return 0;
    }
  }

  for (int i = 0; i < M; i++) {
    if (S[i] == 1) {
      if (count1 == 0) {
        v += C[i] * pow(10, (N - 1));
      }
      count1++;
    } else if (S[i] == 2) {
      if (count2 == 0) {
        v += C[i] * pow(10, (N - 2));
      }
      count2++;
    } else if (S[i] == 3) {
      if (count3 == 0) {
        v += C[i] * pow(10, (N - 3));
      }
      count3++;
    }
  }

  cout << v << endl;
}