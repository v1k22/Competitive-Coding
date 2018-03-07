// Insertion Sort
#include "bits/stdc++.h"
using namespace std;

const int _ = 12345;

int N;
int a[_];

int main () {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
    
    for (int i = 1; i < N; i++) {
        int j = i;
        while (a[j] < a[j-1] && j > 0) {
            swap(a[j], a[j-1]);
            j--;
        }
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
