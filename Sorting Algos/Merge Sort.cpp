#include "bits/stdc++.h"
using namespace std;

const int GOD = 1e5;

int n;
int a[GOD];

void merge_sort(int low, int mid, int high) {
    
    int left_size = mid - low + 1;
    int right_size = high - mid;
    
    int L[left_size], R[right_size];
    for (int i = 0; i < left_size; i++)
        L[i] = a[i + low];
    for (int j = 0; j < right_size; j++)
        R[j] = a[j + mid + 1];
        
    int i = 0;
    int j = 0;
    int k = low;
    while (i < left_size && j < right_size) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }
    
    while (i < left_size) {
        a[k++] = L[i++];
    }
    
    while (j < right_size) {
        a[k++] = R[j++];
    }
}

void merge(int low, int high) {
    if (low < high) {
        int mid = (low + high)/2;
        merge(low, mid);
        merge(mid + 1, high);
        
        merge_sort(low, mid, high);
    }
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    
    merge(0, n-1);
    
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
