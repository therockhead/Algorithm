#include <bits/stdc++.h>
using namespace std;

int valid(int node, int c);

int clr[100000], cnt[100000];
int minCnt = 99999;
vector<vector<int>> adj;

// for track
vector<int> track;
vector<int> save;

void graphClr(int node, int m, int n) { // start node, number of colors, number of nodes
  if (node == n + 1) {
    for (int i = 1; i <= n; i++) {
      // cout << clr[i] << ' ';
      cnt[clr[i]]++;
    }
    //cout << '\n';

      int temp = 0;
      track.clear();
      for (int i = 1; i <= m; i++) {
        track.push_back(clr[i]);
        if (cnt[i] != 0) {
          temp++;
        }
      }
      minCnt = min(minCnt, temp);

      // save
      if (minCnt == temp) {
        save = track;
      }

    return;
  }

  for (int i= 1; i <= m; i++) {
    if (valid(node, i)) {
      clr[node] = i;
      graphClr(node + 1, m, n);
      clr[node] = 0; // reset
    }
  }
  return;
}

int valid (int node, int c) {
  for (auto v : adj[node]) {
    if (clr[v] == c) {
      return 0;
    }
  }
  return 1;
}

int main() {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // call
  graphClr(1, m, n);

  cout << "Minimum Number of Colors: " << minCnt << '\n';
  cout << "Gene Coloring:\n";
  int id = 1;
  for (auto it : save) {
    cout << id << ": "<< it << "\n"; id++;
  }

  return 0;
}