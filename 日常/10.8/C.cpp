#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>
#include<ctime>
#include<bitset>
#include<set>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1010;
const LL INF = 1000000010;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};


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

vector<int> g[SZ];

int b[SZ],fa[SZ],sz[SZ],a[SZ],lsh[SZ],n,use[SZ];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void Union(int a,int b)
{
    if(b > n || a > n || a < 1 || b < 1) return ;
    int x = find(a),y = find(b);
    if(x != y)
        fa[x] = y,sz[y] += sz[x];
}

int main()
{
    int T = read();
    for(int cc = 1;cc <= T;cc ++)
    {
        n = read();
        for(int i = 1;i <= n;i ++)
            a[i] = read(),lsh[i] = a[i];
        sort(lsh + 1,lsh + 1 + n);
        int m = unique(lsh + 1,lsh + n + 1) - lsh - 1;
        for(int i = 1;i <= n;i ++)
        {
            int x = lower_bound(lsh + 1,lsh + 1 + m,a[i]) - lsh;
            g[x].push_back(i);
        }

        int ans = 0;
        for(int l = 1;l <= n;l ++)
        {
            for(int i = 1;i <= n;i ++) fa[i] = i,sz[i] = 1,b[i] = 1,use[i] = 0;
            int r = l;
            for(int i = l;i <= n;i ++)
            {
                int x = lower_bound(lsh + 1,lsh + 1 + m,a[i]) - lsh;
                if(use[x]) break;
                r = i;
                use[x] = 1;
                for(int k = 0;k < g[x].size();k ++)
                    b[g[x][k]] = 0;
            }
            cout << l << " " << r << endl;
            for(int i = 1;i <= n - 1;i ++)
                if(b[i] && b[i + 1])
                    Union(i,i + 1);

            for(int i = 1;i <= n;i ++) cout << b[i] << " "; puts("");
            for(int i = 1;i <= n;i ++) ans = max(ans,sz[i]);
            cout << ans << endl;
            
            for(int i = r;i >= l;i --)
            {
                int x = lower_bound(lsh + 1,lsh + 1 + m,a[i]) - lsh;
                for(int k = 0;k < g[x].size();k ++)
                {
                    int id = g[x][k];
                    if(b[id - 1])
                        Union(id,id - 1);
                    if(b[id + 1])
                        Union(id,id + 1);
                    ans = max(ans,sz[find(id)]);
                }
            }
        }
        printf("Case #%d: %d\n",cc,ans);
    }
    return 0;
}
/*
233
8
3 1 2 1 6 1 2 5

*/
