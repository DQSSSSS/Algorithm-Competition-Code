#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1e9 + 10;


LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int stc[SZ][22],stm[SZ][22];
int Y[SZ],a[SZ],lsh[SZ],mp[SZ];
int n,m;
int askl[SZ],askr[SZ];

void get_st()
{
    for(int i = 1;i <= n;i ++)
        stm[Y[i]][0] = a[i],stc[Y[i]][0] = 1;
    for(int j = 1;j <= log2(m);j ++)
        for(int i = 1;i <= m;i ++)
            stm[i][j] = max(stm[i][j - 1],stm[i + (1 << (j - 1))][j - 1]),
            stc[i][j] = stc[i][j - 1] & stc[i + (1 << (j - 1))][j - 1];
}

int ask_max(int l,int r)
{
    int k = log2(r - l + 1);
    return max(stm[l][k],stm[r - (1 << k) + 1][k]);
}

int ask_can(int l,int r)
{
    int k = log2(r - l + 1);
    return stc[l][k] & stc[r - (1 << k) + 1][k];
}

int main()
{
    n = read();
    for(int i = 1;i <= n;i ++)
        lsh[++ lsh[0]] = Y[i] = read(),a[i] = read();
    for(int i = 2;i <= n;i ++)
        if(Y[i] != Y[i - 1] + 1)
            lsh[++ lsh[0]] = Y[i - 1] + 1;
    int q = read();
    for(int i = 1;i <= q;i ++)
    {
        askl[i] = read(),askr[i] = read();
        lsh[++ lsh[0]] = askl[i];
        lsh[++ lsh[0]] = askr[i];
    }
    sort(lsh + 1,lsh + 1 + lsh[0]);
    m = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;
    for(int i = 1;i <= n;i ++)
    {
        Y[i] = lower_bound(lsh + 1,lsh + 1 + m,Y[i]) - lsh;
        mp[Y[i]] = a[i];
    }
    get_st();
    for(int i = 1;i <= q;i ++)
    {
        int l = askl[i],r = askr[i];
        l = lower_bound(lsh + 1,lsh + 1 + m,l) - lsh;
        r = lower_bound(lsh + 1,lsh + 1 + m,r) - lsh;
        if(l + 1 == r)
        {
            if(!mp[l] || !mp[r]) puts("maybe");
            else if(mp[r] > mp[l]) puts("false");
            else puts("true");
        }
        else
        {
            if(ask_can(l,r))
            {
                if(ask_max(l + 1,r - 1) < mp[r] && mp[l] >= mp[r])
                    puts("true");
                else
                    puts("false");
            }
            else
            {
                int d = ask_max(l + 1,r - 1);
                if((!mp[r] && !mp[l]) || (!mp[l] && d < mp[r]) || (!mp[r] && d < mp[l]) || (mp[l] && mp[r] && mp[r] <= mp[l] && d < mp[r]))
                    puts("maybe");
                else
                    puts("false");
            }
        }
    }
    return 0;
}
