/**
*  @uthor: Md Asifuzzaman
*  ID: 2309005
**/
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>; 

using ll = long long;

const int N = 1e5 + 1;

int dis[N];

void dijkstra(vector<vector<pii>> &adj, int start) {
  int n = adj.size();
  for (int i = 0; i < n; i++) {
    dis[i] = 1e5 + 1;
  }
  
  dis[start] = 0;

  priority_queue<pii, vector<pii>, greater<pii>> q; // min heap
  q.push({0, start}); // {dis, node}

  while (!q.empty()) {
    int v = q.top().second;
    int disV = q.top().first;
    q.pop();

    if (disV > dis[v]) continue;

    // relaxation
    for (auto edge:adj[v]) {
      int to = edge.first;
      int len = edge.second;

      if (dis[v] + len < dis[to]) {
        dis[to] = dis[v] + len;
        q.push({dis[to], to});
      }
    }
  }

}

int main() {
  
  int n, m; // nodes, edges
  cin >> n >> m;

  vector<vector<pii>> adj;
  adj.resize(n + 1);
  
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[v].push_back({u, w});
    adj[u].push_back({v, w});
  }
  int st; cin >> st;
  dijkstra(adj, st);

  for (int i = 1; i <= n; i++)
    cout << i << " : " <<dis[i] << '\n';

  return 0;
}