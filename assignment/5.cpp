/**
	*  @uthor: Md Asifuzzaman
	*  ID: 2309005
**/
#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
string s1, s2;
int n, m;

int ed(int i, int j) {
	if (i == n) return m - j; // insert left
	if (j == m) return n - i; // delete left

	if (dp[i][j] != -1) return dp[i][j];

	if (s1[i] == s2[j]) return dp[i][j] = ed(i + 1, j + 1);

	int deleteOp = ed(i + 1, j);
	int insertionOp = ed(i, j + 1);
	int replaceOp = ed(i + 1, j + 1);

	return dp[i][j] = min({1 + replaceOp, 1 + deleteOp, 1 + insertionOp});
}
void printAlignment() {
  string align1 = "", align2 = "";
  int i = 0, j = 0;

  while (i < n || j < m) {
    // insertions
    if (i == n) {
      align1 += '-';
      align2 += s2[j];
      j++;
    }
    // deletions
    else if (j == m) {
      align1 += s1[i];
      align2 += '-';
      i++;
    }
    // Match
    else if (s1[i] == s2[j]) {
      align1 += s1[i];
      align2 += s2[j];
      i++; j++;
    }
    // Replace
    else if (dp[i][j] == 1 + ed(i + 1, j + 1)) {
      align1 += s1[i];
      align2 += s2[j];
      i++; j++;
    }
    // Delete from s1
    else if (dp[i][j] == 1 + ed(i + 1, j)) {
      align1 += s1[i];
      align2 += '-';
      i++;
    }
    // Insert from s2
    else {
      align1 += '-';
      align2 += s2[j];
      j++;
    }
  }

    cout << "Aligned Sequences:" << endl;
    for (char c : align1) cout << c << " ";
    cout << endl;
    for (char c : align2) cout << c << " ";
    cout << endl;
}

int main() {
	cin >> s1 >> s2;
	n = s1.size();
	m = s2.size();
	memset(dp, -1, sizeof(dp));
	
	int res = ed(0, 0);
	printAlignment();

	cout << "Minimum Edit Distance: " << res << '\n';
	
	return 0;
}