#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;
const int SZ=100050;
const int mod=1e9+7;
const int n2=500000004;
int n,m,k,op;
int tot,x[SZ],y[SZ],a[50][SZ];
int query(int t)
{
    LL ans=a[k][t];
    for (int i=1;i<=tot;i++)
    {
        int kk=x[i];
        if (kk<=t)
        {
            LL s=(1LL*(1+t-kk+1)*(t-kk+1))%mod;
            ans=(ans+s*n2%mod*y[tot])%mod;
        }
    }
    return ans;
}
void adjust()
{
    for (int i=1;i<=tot;i++)
        a[0][x[i]]=(a[0][x[i]]+y[i])%mod;
    for (int i=1;i<=k;i++)
        a[i][1]=a[0][1];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=k;j++)
        	a[i][j]=(a[i-1][j]+a[i][j-1])%mod;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    int limit=sqrt(m) + 1;
    tot=0;
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&op);
        if (op==0)
        {
            tot++;
            scanf("%d%d",&x[tot],&y[tot]);
            if (tot>limit)
            {
                adjust();
                tot=0;
            }
        }
        else
        {
            int t;
            scanf("%d",&t);
            printf("%d\n",query(t));
        }
    }
    return 0;
}
