#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1000000010;

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

int bits[SZ],h[SZ],L[SZ],R[SZ],len1,len2;
char s[SZ],t[SZ];

void add(int x,int d)
{
    for(int i = x;i <= 200000;i += i & -i)
        bits[i] += d;
}

int ask(int x)
{
    int ans = 0;
    for(int i = x;i > 0;i -= i & -i)
        ans += bits[i];
    return ans;
}

void change(int x,char c)
{
    s[x] = c;
    for(int i = L[x];i <= R[x];i ++)
        if(h[i]) add(i,-h[i]),h[i] = 0;
    int now = L[x];
    for(int i = x;i <= x + len2 - 1;i ++)
    {
        int l = i - len2 + 1,r = i;
        if(l < 1) continue;
        bool flag = 1;
        for(int j = l;j <= r;j ++)
            if(s[j] != t[j - l + 1])
                {flag = 0; break;}
        h[now] = flag;
        if(flag) add(now,flag);
        now ++;
    }
//    for(int i = 1;i <= 10;i ++)
//        printf("%d ",h[i]); puts("");
}

void getnxt(char *s)
{
    nxt[1]=nxt[0]=0;
    for(int i = 1;i < len2;i ++)
    {
        int j = nxt[i];
        while(j && s[i] != s[j]) j = nxt[j];
        nxt[i + 1] = a[i] == a[j] ? j + 1 : 0;
    }
}


void init()
{
    memset(bits,0,sizeof(bits));
    memset(L,63,sizeof(L));
    memset(R,0,sizeof(R));
    memset(h,0,sizeof(h));
}

int main()
{
    int T = read();
    while(T --)
    {
        init();
        int n = read();
        scanf("%s%s",s + 1,t + 1);
        len1 = strlen(s + 1),len2 = strlen(t + 1);
        getnxt(t);
        int tot = 0;
        for(int i = 1;i <= len1;i ++)
        {
            int l = i - len2 + 1,r = i;
            if(l < 1) continue;
            bool flag = 1;
            for(int j = l;j <= r;j ++)
                if(s[j] != t[j - l + 1])
                    {flag = 0; break;}
            h[++ tot] = flag;
            add(tot,flag);
            for(int j = l;j <= r;j ++)
                L[j] = min(L[j],tot),R[j] = max(R[j],tot);
        }

        for(int i = 1;i <= len1;i ++)
            printf("%d %d\n",L[i],R[i]);

        for(int i = 1;i <= n;i ++)
        {
            char opt[2];
            scanf("%s",opt);
            int l = read(),r;
            char c[2];
            if(opt[0] == 'Q')
                r = read(),printf("%d\n",ask(L[r]) - ask(R[l] - 1));
            else
                scanf("%s",c),change(l,c[0]);
        }
        puts("");
    }
    return 0;
}
