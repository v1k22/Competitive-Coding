#include "bits/stdc++.h"
using namespace std;

int n;
int a[12345];

int quick_sort(int L, int R) {
    if (L == R) return L;
    int pivot = (L + R)/2;
    swap(a[pivot], a[R]);
    pivot = R;
    
    int i = L - 1;
    int j = L;
    while (j < R) {
        if (a[j] <= a[pivot]) {
            i++;
            swap(a[i], a[j]);
        } j++;
    }
    i++;
    swap(a[i], a[pivot]);
    return i;
}

void quick(int low, int high) {
    if (low < high) {
        int i = quick_sort(low, high);
        quick(i+1, high);
        quick(low, i-1);
    }
}

int main () {
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    
    quick(0, n-1);
    
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    return 0;
}
