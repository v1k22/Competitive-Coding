#include "bits/stdc++.h"
using namespace std;

int n, w;
vector < pair < int , int > > a;

int KnapSack() {
  int dp[n+1][w+1];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= w; j++)
      dp[i][j] = 0;
  
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= w; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
        continue;
      }
      if (a[i-1].first <= j)
        dp[i][j] = max(a[i-1].second + dp[i-1][j - a[i-1].first], dp[i-1][j]);
      else dp[i][j] = dp[i-1][j];
    }
  
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= w; j++) {
      printf(" %d ", dp[i][j]);
    }
    printf("\n");
  }
  
  return dp[n][w];
}

int main () {
  scanf("%d %d", &n, &w);
  a.resize(n);
  
  for (int i = 0; i < n; i++)
    scanf("%d %d", &a[i].first, &a[i].second);
  
  sort(a.begin(), a.end());
  printf("%d\n", KnapSack());
  return 0;
}
