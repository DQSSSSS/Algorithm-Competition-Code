#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> pii;
const int SZ = 200100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

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

int a[SZ];
int lsh[SZ], fk[SZ];
vector<int> vec[SZ];

mt19937 rd(time(0));
int randlr(int l, int r)
{
  return rd() % (r - l + 1) + l;
}

int T = 250;
vector<pii> get(int l,int r) {
    vector<pii> ans,b;
    for (int oo = 1; oo <= T; oo++) {
        int x = a[randlr(l, r)];
        b.push_back({x,1});
    }
    sort(b.begin(),b.end());

    for(int oo = 0,j = 0;oo < b.size();oo ++) {
        if(oo + 1 == b.size() || b[oo].first != b[oo+1].first) {
            ans.push_back({oo-j+1,b[oo].first});
            j = oo + 1;
        }
    }
    sort(ans.begin(),ans.end(),greater<pii>());
    ans.resize(50);
    return ans;
}

int main()
{
  //  printf("%.10f\n",pow(1-pow(1-0.05,250),1e5));
  int n = read(), m = read();
  for (int i = 1; i <= n; i++)
  {
    lsh[i] = a[i] = read();
  }
  sort(lsh + 1, lsh + 1 + n);
  lsh[0] = unique(lsh + 1, lsh + 1 + n) - lsh - 1;
  for (int i = 1; i <= n; i++)
  {
    a[i] = lower_bound(lsh + 1, lsh + 1 + lsh[0], a[i]) - lsh;
    vec[a[i]].push_back(i);
  }

  for (int i = 1; i <= m; i++)
  {
    int l = read(), r = read(), t = read();
    vector<pii> A = get(l,r);

    int len = r - l + 1;
    int ans = -1;
    for(auto pp : A) {
        int x = pp.second;
        int L = lower_bound(vec[x].begin(), vec[x].end(), l) - vec[x].begin();
        int R = upper_bound(vec[x].begin(), vec[x].end(), r) - vec[x].begin() - 1;
        int tt = R - L + 1;
        if (tt * t > len)
            ans = max(ans, x);
    }
    if (ans == -1)
      puts("-1");
    else
      printf("%d\n", lsh[ans]);
  }
}
/*
8 3
1 2 1 4 4 5 3 3
1 2 1
1 4 3
3 8 6

5 100
1 2 3 4 5
1 1 1
*/
