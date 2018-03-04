// Selection sort
#include "bits/stdc++.h"
using namespace std;

const int GOD = 12345;

int N;
int a[GOD];

int main () {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
        
    for (int i = 0; i < N; i++) {
        int index = i;
        for (int j = i+1; j < N; j++) {
            if (a[j] < a[index])
                index = j;
        }
        if (i != index)
            swap(a[i], a[index]);
    }
    
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    return 0;
}
