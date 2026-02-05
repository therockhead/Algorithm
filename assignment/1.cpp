/** 
 *  @uthor: Md Asifuzzaman
 *  ID: 2309005
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N], b[N];
int quick_op = 0, merge_op = 0; // key op cnt

// prototypes
void merge(int l, int mid, int r);
void merge_sort(int l, int r);
int partition(int m, int p);
void quick_sort(int p, int q);

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

  fstream input2;
  input2.open("IO/input2.txt", ios::in);

  input2 >> n;
  for (int i = 0; i < n; i++) {
    input2 >> a[i];
  }
  input2.close();
  
  // func call
  merge_sort(0, n-1);

  output<<'\n'<<"Merge Sort Comparisons: "<<merge_op;
  output<<'\n'<<"Quick Sort Comparisons: "<<quick_op;
  
  output.close();

  return 0;
}

void merge(int l, int mid, int r) {
  int i = l; // start
  int j = mid + 1; // end
  int k = l; // ind for b arr

  while (i <= mid && j <= r) {
    merge_op++;
    if (a[i] <= a[j]) {
      b[k] = a[i];
      i++;
    }
    else {
      b[k] = a[j];
      j++;
    }
    k++; // b index
  }
  merge_op++;
  if (i > mid) { // rest
    for (int m = j; m <= r; m++) {
      b[k] = a[m];
      k++;
    }
    
  }
  else if (j > r) {
    // merge_op++;
    for (int m = i; m <= mid; m++) {
      b[k] = a[m];
      k++;
    }
  }

  for (int idx = l; idx <= r; idx++) {
    a[idx] = b[idx];
  }
}

void merge_sort(int l, int r) { // first last
  if (l < r) {
    // merge_op++;
    int mid = (l+r)/2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, mid, r);
  }
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
