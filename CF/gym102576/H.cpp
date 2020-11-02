#include <bits/stdc++.h>

using namespace std;

#define N 605
#define eps 1e-7

int x[N], y[N];
double dist[2 * N][2 * N];

double ask_dist(int i, int j)
{
  double xx = x[i] - x[j];
  double yy = y[i] - y[j];
  return sqrt(xx * xx + yy * yy);
}

double f[2 * N][2 * N];

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
      scanf("%d%d", &x[i], &y[i]);
    }
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= 2 * n; i++)
    {
      for (int j = 1; j <= 2 * n; j++)
      {
        if (i == j)
          dist[i][j] = 0;
        else
          dist[i][j] = -1e18;
      }
    }
    for (int i = 1; i <= 2 * n; i++)
      for (int j = 1; j <= 2 * n; j++)
      {
        f[i][j] = -1e18;
      }
    for (int i = 1; i <= m; i++)
    {
      int u, v;
      scanf("%d%d", &u, &v);
      dist[v][u] = dist[u][v] = ask_dist(u, v);
      f[v][u] = f[u][v] = dist[u][v];
      f[v][n + u] = f[n + u][v] = dist[v][n + u] = dist[n + u][v] = dist[u][v];
      f[u][n + v] = f[n + v][u] = dist[u][n + v] = dist[n + v][u] = dist[u][v];
      f[n + u][n + v] = f[n + v][n + u] = dist[n + u][n + v] = dist[n + v][n + u] = dist[u][v];
    }
    double ans = -1e18;
    for (int k = n - 2; k >= 1; k--)
    {
      for (int i = 1; i <= 2 * n; i++)
      {
        if (i + k > 2 * n)
          break;
        for (int j = i + k + 1; j < i + n; j++)
        {
          f[i][i + k] = max(max(f[i][i + k], f[i][j] + dist[j][i + k]), -1e18);
          f[i][i + k] = max(max(f[i][i + k], f[j][i] + dist[i][i + k]), -1e18);
        }
        for (int j = max(1, i + k - n + 1); j < i; j++)
        {
          f[i + k][i] = max(max(f[i + k][i], f[i + k][j] + dist[j][i]), -1e18);
          f[i + k][i] = max(max(f[i + k][i], f[j][i + k] + dist[i + k][i]), -1e18);
        }
      }
    }
    for (int i = 1; i <= 2 * n; i++)
      for (int j = 1; j <= 2 * n; j++)
        ans = max(ans, f[i][j]);
    printf("%.10f\n", ans);
  }
}
/*
7
0 0
260338181 86092533
323066179 107441010
424697382 278447352
71444106 1000000000
-575302618 804979842
-258577414 97804732
20
2 3
2 5
1 3
7 4
2 1
5 3
6 2
7 5
4 2
3 6
1 7
5 6
4 6
4 5
3 4
7 2
6 1
1 5
7 6
4 1
5
0 0
713930457 800419774
94147955 958520832
-286069543 1000000000
-262432976 698118841
8
3 1
1 4
5 3
4 2
5 1
2 1
2 3
4 3
*/
