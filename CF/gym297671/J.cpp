#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;
LL read()
{
  LL n = 0;
  char a = getchar();
  bool flag = 0;
  while (a > '9' || a < '0')
  {
    if (a == '-')
      flag = 1;
    a = getchar();
  }
  while (a <= '9' && a >= '0')
  {
    n = n * 10 + a - '0', a = getchar();
  }
  if (flag)
    n = -n;
  return n;
}

int n,lg2[SZ];
LL a[SZ], goal;

LL f(LL x)
{
  return lg2[x] + 1;
}
bool check(LL T)
{
  vector<pll> A;
  A.push_back({-1e17, 0});
  for (int i = 1, j = 1; i <= n; i++)
  {
    if (i == n || a[i + 1] != a[i])
    {
        A.push_back({a[i], i - j + 1});
        j = i + 1;
    }
  }
  reverse(A.begin(), A.end());
  LL sum = 0, cnt = 0;
  for (int i = 0; i + 1 < A.size(); i++)
  {
    cnt += A[i].second;
    if ((A[i].first - A[i + 1].first) >= (T - sum + f(cnt)) / f(cnt)) {
        LL r = A[i].first - (T - sum) / f(cnt);
        if (r + T > goal)
        return true;
    }
    sum += f(cnt) * (A[i].first - A[i + 1].first);
  }
  return false;
}

int main()
{
  n = read() - 1;
  goal = read();
  for (int i = 1; i <= n; i++)lg2[i] = log2(i);
  for (int i = 1; i <= n; i++)
    a[i] = read();
  sort(a + 1, a + 1 + n);
  LL l = 0, r = 2e16 + 10;
  while (r - l > 1)
  {
    LL mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r - 1 << endl;
}
