/**
*  @uthor: Md Asifuzzaman
*  ID: 2309005
**/

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>; 

using ll = long long;

const int N = 1000;

int dis[N][N];
vector<vector<pii>> path; // (x, y)

void gridRelaxation(vector<vector<int>>& grid, int start) {
  int n = grid.size();
  int m = grid[0].size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dis[i][j] = 1e5;
    }
  }

  dis[start][start] = grid[0][0];
  path[0][0] = {0, 0};

  int rx[] = {-1, 1, 0, 0};
  int ry[] = {0, 0, -1, 1};

  using vpp = pair<int, pair<int, int>>;

  priority_queue<vpp, vector<vpp>, greater<vpp>> q;

  q.push({dis[start][start], {start, start}});

  while (!q.empty()) {
    int x = q.top().second.first;
    int y = q.top().second.second;

    int disV = q.top().first;

    q.pop();

    if (disV > dis[x][y]) continue;

    for (int i = 0; i < 4; i++) {
      int nx = x + rx[i];
      int ny = y + ry[i];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m) { // coordinate valid ?
       if (dis[x][y] + grid[nx][ny] < dis[nx][ny]) {
         dis[nx][ny] = dis[x][y] + grid[nx][ny];
         q.push({dis[nx][ny], {nx, ny}});
         path[nx][ny] = {x, y};
       }
      }
    } 
  }
}

int main() {
  
  int n, m; // nodes, edges
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  path.resize(n, vector<pii> (m, {-1, -1}));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j]; // cost
    }
  }

  gridRelaxation(grid, 0);

// TESTing updated dis[][]
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     cout << dis[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  cout << "Shortest Path:\n";

  vector<pair<int, int>> seq;

  pii curr = path[n-1][m-1];
  seq.push_back({n-1, m-1});

  while (curr != path[0][0]) {
    int newx = curr.first;
    int newy = curr.second;

    curr = path[newx][newy];
    seq.push_back({newx, newy});
  }
  seq.push_back({0, 0});
  reverse(seq.begin(), seq.end());

  for (int i = 0; i < seq.size(); i++) {
    if (i != seq.size() - 1) {
      cout << "(" << seq[i].first << ',' << seq[i].second << ")"  << " -> ";
    }
    else {
      cout << "(" << seq[i].first << ',' << seq[i].second << ")\n";
    }
  }
  cout << "Total Interaction Cost: " << dis[n-1][m-1]; 

  return 0;
}