#include <bits/stdc++.h>

using namespace std;

#define N 200005

int a[N];
int lsh[N];
int num[10000005];
int dp[N], tot;
int id[10000005];
int cnt = 0;


int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &a[i]);
    lsh[i] = a[i];
    num[a[i]]++;
  }
  sort(lsh + 1, lsh + n + 1);
  int mx = lsh[n];
  tot = unique(lsh + 1, lsh + n + 1) - lsh - 1;
  for (int i = 1; i <= n; i++)
  {
    id[a[i]] = lower_bound(lsh + 1, lsh + tot + 1, a[i]) - lsh;
  }
  int ans = 0;
  for (int i = 1; i <= tot; i++)
  {
    dp[i] += num[lsh[i]];
    ans = max(ans, dp[i]);
    int x = lsh[i];
    for (int j = x + x; j <= mx; j += x)
    {
      if (num[j])
      {
        int t = id[j];
        dp[t] = max(dp[t], dp[i]);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
