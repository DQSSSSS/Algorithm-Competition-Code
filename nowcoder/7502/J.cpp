#include <bits/stdc++.h>

using namespace std;

#define N 200005
#define MOD 1000000007

int a[N];
int f[20][N]; // S1..Sn match Ai...
int g[20][N]; // A1...An match Si...
long long fac[N];
int n, m;

void init(int k)
{
  for (int i = 0; i <= k+1; i++)
    for (int j = 0; j <= (2 << k) - 1; j++)
      f[i][j] = g[i][j] = 0;
  for (int i = 1; i <= n; i++)
  {
    if (a[i] == 1)
      f[1][i] = 1;
    else
      f[1][i] = 0;
  }
  for (int j = 2; j <= k; j++)
  {
    for (int i = 1; i <= n; i++)
    {
      f[j][i] = f[j - 1][i];
      if (i + (1 << j - 1) - 1 <= n)
      {
        f[j][i] = f[j][i] + (a[i + (1 << j - 1) - 1] == j);
      }
      if (i + (1 << j - 1) <= n)
        f[j][i] = f[j][i] + f[j - 1][i + (1 << j - 1)];
    }
  }
  for (int i = 1; i <= n; i++)
  {
    if (a[i] == 1)
      g[1][i] = 1;
    else
      g[1][i] = 0;
  }
  for (int j = 2; j <= k; j++)
  {
    for (int i = 1; i <= (1 << j) - 1; i++)
    {
      if (i == (1 << j - 1))
      {
        g[j][i] = (a[1] == j) + f[j - 1][2];
      }
      else if (i > (1 << j - 1))
      {
        g[j][i] = g[j - 1][i - (1 << j - 1)];
      }
      else
      {
        g[j][i] = g[j - 1][i] + (j == (a[(1 << j - 1) - i + 1])) + f[j - 1][(1 << j - 1) - i + 2];
      }
    }
  }
}

int main()
{
//	freopen("J.in","r",stdin); freopen("J.out","w",stdout);
  fac[0] = 1;
  for (int i = 1; i < N; i++)
    fac[i] = 1LL * fac[i - 1] * 2 % MOD;
  while (scanf("%d%d", &n, &m) != EOF)
  {
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &a[i]);
    }
    a[n + 1] = 0;
    int k = 1;
    while (n > (1 << k) - 1)
      k++;
    init(k);
    // for (int j = 1; j <= k; j++)
    // {
    //   for (int i = 1; i <= n; i++)
    //   {
    //     printf("j : %d i : %d %d\n", j, i, f[j][i]);
    //   }
    // }
    // puts("-----------------------------------------------");
    // for (int j = 1; j <= k; j++)
    // {
    //   for (int i = 1; i <= n; i++)
    //   {
    //     printf("j : %d i : %d %d\n", j, i, g[j][i]);
    //   }
    // }
    int mx = 1000000000;
    long long ans = 0;
    for (int i = 1; i <= (1 << k) - 1; i++)
    {
      if (k == m && i + n - 1 > (1 << k) - 1)
        break;
      if (i + n - 1 < (1 << k))
      {
        mx = min(mx, n - g[k][i]);
        ans = ans + 1LL * (n - g[k][i]) * fac[m - k] % MOD;
        ans %= MOD;
      }
      else
      {
        int t = g[k][i];
        if ((1 << k) - i + 2 <= n)
          t = t + f[k][(1 << k) - i + 2];
        mx = min(mx, n - t);
        ans = ans + 1LL * (n - t) * (fac[m - k] - 1) % MOD;
        ans %= MOD;
        if (a[(1 << k) - i + 1] > k)
        {
          mx = min(mx, n - t - 1);
          ans = ans + MOD - (fac[m - a[(1 << k) - i + 1]]);
          ans %= MOD;
        }
      }
    }
    //printf("%d %lld\n", mx, ans);
    if (k != m)
    {
      int t = f[k][2];
      if (a[1] > k)
        mx = min(mx, n - t - 1);
      else
        mx = min(mx, n - t);
      ans = ans + 1LL * (n - t) * (fac[m - k] - 1) % MOD;
      if (a[1] > k)
      {
        ans = ans + MOD - (fac[m - a[1]]);
        ans %= MOD;
      }
    }
    ans = (ans + MOD) % MOD;
    printf("%d %lld\n", mx, ans);
  }
  return 0;
}
