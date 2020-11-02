#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2000 + 5;
ll dis[N];
int n, a[N][N];
void dijkstra()
{
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
  memset(dis, 0x3f, sizeof dis);
  dis[0] = 0;
  q.push({0, 0});
  while (!q.empty())
  {
    ll d = q.top().first;
    int u = q.top().second;
    q.pop();
    if (d > dis[u])
      continue;
    for (int v = 1; v <= n; v++)
      if (dis[v] > dis[u] + a[u][v])
      {
        dis[v] = dis[u] + a[u][v];
        q.push({dis[v], v});
      }
  }
}

int fa[N];
bool vis[N];
int main()
{
  scanf("%d", &n);
  memset(a, 0x3f, sizeof a);
  ll ad = 0;
  for (int i = 1; i <= n; i++)
  {
    int x, s;
    scanf("%d%d", &x, &s);
    for (int j = 0; j <= n; j++)
    {
      int x;
      scanf("%d", &x);
      a[j][i] = x - s;
    }
    fa[i] = x;
    a[x][i] = 0;
    ad += s;
  }
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++)
  {
    int p = i;
    for (int j = 1; j <= n; j++)
    {
      p = fa[p];
    }
    if (vis[p])
      continue;
    vector<int> cycle;
    cycle.clear();
    int dqs = p;
    cycle.emplace_back(dqs);
    vis[dqs] = true;
    for (int j = fa[dqs]; j != dqs; j = fa[j])
    {
      cycle.emplace_back(j);
      vis[j] = true;
    }
    int mn = a[n][dqs];
    for (auto x : cycle)
    {
      mn = min(mn, a[n][x]);
    }
    for (auto x : cycle)
    {
      for (int j = 0; j <= n; j++)
      {
        a[j][x] -= mn;
        a[j][x] = max(0, a[j][x]);
      }
    }
    ad = ad + mn;
  }
  ll ans = 0;
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      printf("%d ", a[i][j]);
    }
    puts("");
  }
  dijkstra();
  ans = dis[n];
  printf("%lld\n", ans + ad);
}

