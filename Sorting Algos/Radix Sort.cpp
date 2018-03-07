#include "bits/stdc++.h"
using namespace std;

int n;
vector < int > a;
vector < int > HashMap[11];

void print_A(vector < int > x);

int find_digits(int X) {
  int c = 0;
  while (X > 0) {
    c++;
    X /= 10;
  }
  return c;
}

int get_digit(int x, int ith) {
  int cnt = 1;
  int result = 0;
  while (cnt <= ith) {
    cnt++;
    result = x % 10;
    x /= 10;
  }
  return result;
}

void sort_digits(int q) {
  for (int i = 0; i < n; i++) {
    int d = get_digit(a[i], q);
    HashMap[d].push_back(a[i]);
  }
  int index = 0;
  for (int d = 0; d < 10; d++) {
    for (int i = 0; i < HashMap[d].size(); i++) {
      a[index++] = HashMap[d][i];
    }
    HashMap[d].clear();
  }
}

void Radix_Sort(int LMT) {
  for (int i = 1; i <= LMT; i++)
    sort_digits(i);
}

int main () {
  scanf("%d", &n);
  a.resize(n);
  
  int maxx = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    maxx = max(maxx, a[i]);
  }
  
  printf("Unsorted = ");
  print_A(a);
  int LMT = find_digits(maxx);
  Radix_Sort(LMT);
  printf("Sorted   = ");
  print_A(a);
  return 0;
}

void print_A(vector < int > x) {
  for (int i = 0; i < x.size(); i++)
    printf("%d ", x[i]);
  printf("\n");
}
