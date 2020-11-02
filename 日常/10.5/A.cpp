#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<ctime>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 2000010;
const LL INF = 1000000010;
const LL mod = 1000000007;

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

map<ULL,bool> maps;

int n,m;

struct matrix
{
    int n,m;
    char mp[120][120];
    matrix() {}
    matrix(int a,int b) : n(a),m(b) { memset(mp,0,sizeof(mp)); }
    void print()
    {
        cout << n << " " << m << endl;
        for(int i = 1;i <= n;i ++)
            cout << (mp[i] + 1) << endl;
    }
}f[10010],r1,r2,r3;

matrix rotate(const matrix &a)
{
    matrix ans(a.m,a.n);
    for(int j = 1;j <= a.m;j ++)
        for(int i = a.n;i >= 1;i --)
            ans.mp[j][a.n - i + 1] = a.mp[i][j];
    return ans;
}

bool operator ==(const matrix &a,const matrix &b)
{
    if(a.n != b.n || a.m != b.m) return false;
    for(int i = 1;i <= a.n;i ++)
        for(int j = 1;j <= a.m;j ++)
            if(a.mp[i][j] != b.mp[i][j])
                return false;
    return true;
}

ULL get_h(const matrix &a)
{
    ULL ans = 0;
    for(int i = 1;i <= a.n;i ++)
        for(int j = 1;j <= a.m;j ++)
            ans = ans * 3 + (a.mp[i][j] == '.' ? 1 : 2);
    return ans;
}


char mp[120][120];
bool vis[120][120];

int main()
{
    n = read(),m = read();
    for(int i = 1;i <= n;i ++)
        scanf("%s",mp[i] + 1);
    int tot = 0;
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1,k;j <= m;j = k + 1)
        {
            k = j;
            if(!vis[i][j] && mp[i][j] != '#')
            {
                while(k <= m && mp[i][k + 1] != '#') k ++;
                int r = i;
                while(r <= n && mp[r + 1][j] != '#') r ++;
                f[++ tot].n = r - i + 1;
                f[tot].m = k - j + 1;
                for(int a = i;a <= r;a ++)
                    for(int b = j;b <= k;b ++)
                        vis[a][b] = 1,f[tot].mp[a - i + 1][b - j + 1] = mp[a][b];
            }
        }
    }
//    cout << tot<< endl;
/*    rotate(f[2]).print();
    rotate(rotate(f[2])).print();
    rotate(rotate(rotate(f[2]))).print();*/
    int ans = 0;
    for(int i = 1;i <= tot;i ++)
    {
        ULL x1 = get_h(f[i]);
        ULL x2 = get_h(r1 = rotate(f[i]));
        ULL x3 = get_h(r2 = rotate(r1));
        ULL x4 = get_h(r3 = rotate(r2));
        if(maps[x1] || maps[x2] || maps[x3] || maps[x4])
            ans ++;
        maps[x1] = 1;
        maps[x2] = 1;
        maps[x3] = 1;
        maps[x4] = 1;
    }
    printf("%d\n",tot - ans);
    return 0;
}
/*
11 16
################
#....#++++#+...#
#....#++.+#+...#
#....#.++.#++.+#
#....#....#++++#
################
#....#.+..#++++#
#..++#.+..######
#+...#....#.#+.#
#+...#..++#.#..#
################


*/
