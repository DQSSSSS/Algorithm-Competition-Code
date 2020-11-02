#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<bitset>
#include<math.h>
#include<vector>
#include<string>
#include<stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N=4010;
const int mod=100000000;
const int MOD1=1000000007;
const int MOD2=1000000009;
const double EPS=0.00000001;
typedef long long ll;
const ll MOD=1000000007;
const int MAX=1000000010;
const ll INF=1ll<<55;
const double pi=acos(-1.0);
typedef double db;
typedef unsigned long long ull;
int d[25],f[1050000];
int get(int x) {
    int i,bo=0,w;
    for (i=1;i<=20;i++)
    if ((1<<i)-1==x) return 0;
    memset(d,0,sizeof(d));
    for (i=0;i<20;i++)
    if ((1<<i)>x) break ;
    else if (((1<<i)&x)==0) { bo=1;w=i; }
        else if (bo) {
            d[f[x-(1<<i)+(1<<w)]]=1;
        }
    for (i=0;i<25;i++)
    if (!d[i]) return i;
}
int main()
{
	freopen("in.txt","r",stdin); freopen("std.txt","w",stdout);
    int i,j,g,x,n,t,sum,ans;
    f[0]=0;for (i=1;i<=(1<<20);i++) f[i]=get(i);
   // for (i=0;i<=(1<<20);i++) cout << f[i] << endl;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);ans=0;
        for (i=1;i<=n;i++) {
            scanf("%d", &g);sum=0;
            for (j=1;j<=g;j++) {
                scanf("%d", &x);sum+=1<<(20-x);
            }
            ans^=f[sum];
        }
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
