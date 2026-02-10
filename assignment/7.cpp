#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
string genes[N];
int dp[N];
int n;
void test();
int maxLen = 0;
int parent[N];
int last = 0;

int lis(int i) {
  // Base Case
  if (dp[i] != -1) return dp[i];
    int best_prev_len = 0;
    parent[i] = -1; 

    for (int j = 0; j < i; j++) {
      int len_j = lis(j);
      
      if (genes[i] > genes[j]) {
        if (len_j > best_prev_len) {
          best_prev_len = len_j;
          parent[i] = j;
        }
      }
    }

    return dp[i] = 1 + best_prev_len;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> genes[i];
	}

	memset(dp, -1, sizeof(dp));
	memset(parent, -1, sizeof(parent));

	for (int i = 0; i < n; i++) {
    if (lis(i) > maxLen) {
        maxLen = lis(i);
        last = i;
    }
  }

  cout << "Longest Increasing Subsequence:\n";
	vector<string> res;
  for (int curr = last; curr != -1; curr = parent[curr]) {
    res.push_back(genes[curr]);
  }
  reverse(res.begin(), res.end());

	for (auto it: res) {
		cout << it << ' ';
	}

	cout << "\nLength of LIS: " << maxLen << '\n';

	return 0;
}

void test() {
	for (auto it: genes) {
		cout << it << ' ';
	}
}