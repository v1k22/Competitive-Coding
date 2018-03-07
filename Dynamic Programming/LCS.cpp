#include "bits/stdc++.h"
using namespace std;

int a, b;
string A, B;

int LCS (int a, int b){
  if (a == 0 || b == 0)
    return 0;
  if (A[a] == B[b])
    return 1 + LCS(a - 1, b - 1);
  else return max(LCS(a - 1, b), LCS(a, b - 1));
}

int LCS_it(int a, int b) {
  int dp[a + 1][b + 1];
  
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      if (A[i-1] == B[j-1])
        dp[i][j] = 1 + dp[i-1][j-1];
      else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  return dp[a][b];
}

int main () {
  freopen("in.txt", "r", stdin);
  cin >> A;
  cin >> B;
  a = (int)A.length();
  b = (int)B.length();
  
  cout << LCS(a, b) << endl;
  cout << LCS_it(a, b) << endl;
  return 0;
}
