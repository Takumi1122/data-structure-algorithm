#include "bits/stdc++.h"
using namespace std;
const long long INF = 1LL << 62;
int N, M, K, X[2000];
long long Y[2000];
vector<pair<int, long long>> edge[2000];
long long cost[2000][4000];

long long dykstra() {
  priority_queue<pair<long long, pair<int, int>>> que;
  cost[0][0] = 0;
  que.push({0, {0, 0}});
  while (!que.empty()) {
    long long c = -que.top().first;
    long long sta = que.top().second.first;
    long long flo = que.top().second.second;
    que.pop();
    if (flo < K && cost[sta][flo + X[sta]] > c + Y[sta]) {
      cost[sta][flo + X[sta]] = c + Y[sta];
      que.push({-cost[sta][flo + X[sta]], {sta, flo + X[sta]}});
    }
    for (int i = 0; i < edge[sta].size(); i++) {
      if (cost[edge[sta][i].first][flo] > c + edge[sta][i].second) {
        cost[edge[sta][i].first][flo] = c + edge[sta][i].second;
        que.push({-cost[edge[sta][i].first][flo], {edge[sta][i].first, flo}});
      }
    }
  }
  long long answer = INF;
  for (int i = 0; i < K; i++) answer = min(answer, cost[N - 1][K + i]);
  if (answer == INF) answer = -1;
  return answer;
}

int main() {
  cin >> N >> M >> K;
  for (int i = 0; i < M; i++) {
    int A, B;
    long long C;
    cin >> A >> B >> C;
    A--;
    B--;
    edge[A].push_back(make_pair(B, C));
    edge[B].push_back(make_pair(A, C));
  }
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
    for (int j = 0; j < 2 * K; j++) cost[i][j] = INF;
  }
  cout << dykstra() << endl;
}