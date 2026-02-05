#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N];
int quick_op = 0;

int merge_sort() {
  
}
int partition(int m, int p) {
  int pivot = a[m];
  int i = m;
  int j = p;

  do {
    do {
      quick_op++;
      i++;
    } while (a[i] < pivot);
    
    do {
      quick_op++;
      j--;
    } while (a[j] > pivot);

    if (i < j) {
      quick_op++;
      swap(a[i], a[j]);
    }

  } while (i < j);

  a[m] = a[j];
  a[j] = pivot;

  return j;
}

void quick_sort(int p, int q) {
  if (p < q) {
    int j = partition(p, q + 1);
    quick_sort(p, j - 1);
    quick_sort(j + 1, q);
  }
}

int main() {
  fstream input;
  input.open("IO/input.txt", ios::in);

  fstream output;
  output.open("IO/output.txt", ios::out | ios::trunc);

  int n;
  input >> n;
  for (int i = 0; i < n; i++) {
    input >> a[i];
  }
  input.close();

  // func call
  quick_sort(0, n - 1);


  output << "Sorted Values:" << '\n';
  for (int i = 0; i < n; i++) {
    output << a[i] << ' ';
  }

  output << '\n' << quick_op << '\n';
  output.close();

  return 0;
}
