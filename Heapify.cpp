#include "bits/stdc++.h"
using namespace std;

const int oo = 1e4;

int N;
int a[oo];

void print_A(int a[], int x);

// O(N) time complexity
void heapify(int index) {
    int left_child = 2*index + 1;
    int right_child = 2*index + 2;
    int largest = index; 
    
    if (left_child < N && a[left_child] > a[largest]) {
        largest = left_child;
    }
    if (right_child < N && a[right_child] > a[largest]) {
        largest = right_child;
    }
    if (largest != index) {
        swap(a[largest], a[index]);
        heapify(largest);
    }
}

void build_heap() {
    for (int i = (N/2 -1); i >= 0; i--)
        heapify(i);
}

int main () {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
        
    build_heap();
    print_A(a, N);
    return 0;
}

void print_A(int a[], int x) {
    printf("\n");
    for (int i = 0; i < x; i++)
        printf("%d ", a[i]);
    printf("\n");
}
