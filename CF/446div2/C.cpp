#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    scanf("%I64d",&n);
    return n;
}

int a[SZ],n,b[SZ];

int gcd(int a,int b) { b == 0 ? a : gcd(b,a % b); }

int main()
{
    scanf("%d",&n);
    int x = 0;
    for(int i = 1;i <= n;i ++)
        scanf("%d",&a[i]),x = __gcd(x,a[i]);
    if(x != 1) { puts("-1"); return 0; }
    int Minans = 19260817,tot = 0;
    for(int i = 1;i <= n;i ++) if(a[i] != 1) tot ++;
    for(int i = 1;i <= n;i ++)
    {
        int x = 0;
        for(int j = i;j <= n;j ++)
        {
            x = __gcd(x,a[j]);
            if(x == 1) { Minans = min(Minans,j - i); break;}
        }
    }
    if(tot != n) cout << tot << endl;
    else cout << Minans + n - 1 <<endl;
    return 0;
}
/*
6
6 2 12 9 90 45


*/
