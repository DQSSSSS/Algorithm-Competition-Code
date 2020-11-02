#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 200010;
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

int st[SZ][21],N = 200000;

void insert(int pos,int d)
{
    st[pos][0] = d;
    for(int i = 1;i <= log2(N - pos + 1);i ++)
        st[pos][i] = max(st[pos][i - 1],st[pos + (1 << (i - 1))][i - 1]);
}

int ask_max(int l,int r)
{
    int k = log2(r - l + 1);
    return max(st[l][k],st[r - (1 << k) + 1][k]);
}

int main()
{
    int n = read(),p = read();
    int t = 0,now = N;
    while(n --)
    {
        char s[2];
        int x;
        scanf("%s%d",s,&x);
        if(s[0] == 'Q') printf("%d\n",t = ask_max(now + 1,now + x));
        else insert(now,(x + t) % p),now --;
    }
    return 0;
}
