#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,m,a[SZ],st[SZ][22],lg2[SZ];

void get_st()
{
    for(int i = 1;i <= n;i ++) st[i][0] = a[i];
    for(int j = 1;j <= lg2[n];j ++)
        for(int i = 1;i <= n;i ++)
            st[i][j] = min(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
}

int ask_min(int l,int r)
{
    int k = lg2[r - l + 1];
    return min(st[l][k],st[r - (1 << k) + 1][k]);
}

int Div(int L,int R,int x)
{
    int l = L - 1,r = R;
    while(r - l > 1)
    {
        int mid = l + r >> 1;
        if(ask_min(L,mid) <= x) r = mid;
        else l = mid;
    }
    return r;
}

int main()
{
    int T = read();
    for(int i = 1;i <= 100000;i ++) lg2[i] = log2(i);
    while(T --)
    {
        n = read();
        for(int i = 1;i <= 2 * n;i ++)
            for(int j = 0;j <= lg2[n];j ++)
                st[i][j] = 0;
        for(int i = 1;i <= n;i ++)
            a[i] = read();
        get_st();
        m = read();
        while(m --)
        {
            int l = read(),r = read();
            if(l == r) { printf("%d\n",a[l]); continue; }
            int x = a[l],pos = l;
            while(233)
            {
                if(pos >= r || ask_min(pos + 1,r) > x) break;
                pos = Div(pos + 1,r,x);
                x %= a[pos];
            }
            printf("%d\n",x);
        }
    }
    return 0;
}
/*
233
5
5 3 1 4 2
233

*/
