#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#include<cmath>
#include<set>
using namespace std;

typedef long long LL;
const int SZ = 2000010;
const int INF = 1000000010;
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

int fa[SZ],L[SZ],R[SZ];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void merge(int a,int b)
{
    int x = find(a),y = find(b);
    if(x != y)
        fa[x] = y,L[y] = min(L[y],L[x]),R[y] = max(R[y],R[x]);
}

int opt[SZ][2],tmp[SZ][2];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int T = read();
    while(T --)
    {
        int n = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        for(int i = 0;i <= n;i ++) fa[i] = L[i] = R[i] = i;

        int tot = 0;
        for(int i = 1,j;i <= n;i = j)
        {
            j = i + 1;
            bool flag = 0;
            while(j <= n && a[j - 1] > a[j])
                merge(j,j - 1),j ++;
            if(i != j - 1) opt[++ tot][0] = i,opt[tot][1] = j - 1;
        }

        cout << tot << endl;
        for(int i = 1;i <= tot;i ++) printf("%d %d\n",opt[i][0],opt[i][1]);
        puts("");
        cout << ans << endl;
        for(int i = nx[0];i;i = nx[i]) printf("%d ",a[i]);
        puts("");

        while(233)
        {
            int tot2 = 0;
            for(int i = 1;i <= tot;i ++)
            {
                int l = L[find(opt[i][0] - 1)];
                int r = nx[opt[i][1]];
                if(pr[nx[l]] != l || nx[pr[l]] != l) continue;
                if(pr[nx[r]] != r || nx[pr[r]] != r) continue;
                while(r && iscz(r) && a[r] > a[pr[r]]) del(r),r = nx[r],ans --;
                if(l && r && 1 <= l && r <= n && a[l] > a[r])
                    del(l),del(r),tmp[++ tot2][0] = l,tmp[tot2][1] = r,ans -= 2;
            }
            puts("");
            cout << ans << endl;
            for(int i = nx[0];i;i = nx[i]) printf("%d ",a[i]); puts("");
            puts("");

            cout << tot2 << endl;
            for(int i = 1;i<= tot2;i ++) cout << tmp[i][0] << " " << tmp[i][1] << endl;

            if(!tot2) break;
            tot = tot2;
            for(int i = 1;i <= tot;i ++) opt[i][0] = tmp[i][0],opt[i][1] = tmp[i][1];
        }
        printf("%d\n",ans);
        for(int i = nx[0];i;i = nx[i]) printf("%d ",a[i]);
        puts("");
    }
    return 0;
}

/*

1
10
1 9 9 6 9 7 2 9 3 3

233
5
5 4 3 2 1

1
10
2 4 1 4 8 6 2 9 4 6

2 4 6

1
10
5 6 7 8 9 0 1 2 3 4

1
10
5 10 8 6 1 6 7 9 1 5

1
20
8 8 2 6 6 8 5 6 5 1 5 10 7 6 6 1 4 6 4 6
8 6 6  5 4 6


*/
