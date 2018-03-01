// Dynamic Programming easiest one
#include "bits/stdc++.h"
using namespace std;

int N;
int a[1234];
int dp[1234];

int main () {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    
    int sum = a[0];
    dp[0] = a[0];
    for (int i = 1; i < N; i++) {
        sum += a[i];
        dp[i] = max(sum, dp[i-1]);
        if (sum < 0) sum = 0;
    }
    cout << dp[N-1] << endl;
    return 0;
}
