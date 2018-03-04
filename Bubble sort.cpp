// Bubble shor
#include "bits/stdc++.h"
using namespace std;

const int N = 12345;

int n;
int a[N];

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%d", a + i);
    
    while (true) {
        bool found = false;
        for (int i = 1; i < n; i++) {
            if (a[i-1] > a[i]) {
                found = true;
                swap(a[i-1], a[i]);
            }
        }
        if (!found) break;
    }
    
    for (int i = 0; i < n; i++) 
        printf("%d ", a[i]);
    return 0;
}
