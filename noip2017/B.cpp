#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

struct haha
{
    char s,i,l[10],r[10];
    int d;
}l[SZ];

int get_num(char s[])
{
    int n = strlen(s);
    int ans = 0;
    for(int i = 0;i < n;i ++) ans = ans * 10 + s[i] - '0';
    return ans;
}

int n;
char g[10];
int S[SZ];
bool mp[310];
int check()
{
    LL tmp = 0,ans = 0;
    int top = 0;
    memset(mp,0,sizeof(mp));
    for(int i = 1;i <= n;i ++)
    {
        if(l[i].s == 'E')
        {
            tmp -= l[S[top]].d; mp[l[S[top]].i] = 0;
            if(-- top < 0) return -1;
        }
        else
        {
            char opt = l[i].i;
            if(mp[opt]) return -1;
            mp[opt] = 1;
            S[++ top] = i;
            tmp += l[i].d;
            ans = max(ans,tmp);
        }
    }
    if(top) return -1;

    int gn = 0;
    if(g[2] == '1')
    {
        gn = 1;
    //    printf("%lld %d\n",ans,gn);
        if(ans == 0) return 1;
        return 0;
    }
    else
    {
        int len = strlen(g);
        for(int i = 4;i < len - 1;i ++) gn = gn * 10 + g[i] - '0';
    //    printf("%lld %d\n",ans,gn);
        if(ans == gn) return 1;
        return 0;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    LL T = read();
    while(T --)
    {
        n = read(); scanf("%s",g);
        for(int i = 1;i <= n;i ++)
        {
            char c[2];
            scanf("%s",c);
            l[i].s = c[0];
            if(c[0] == 'F')
            {
                char o[2];
                scanf("%s%s%s",o,l[i].l,l[i].r);
                l[i].i = o[0];

                if(l[i].l[0] == 'n' && l[i].r[0] == 'n') l[i].d = 0;
                else if(l[i].l[0] == 'n') l[i].d = -INF;
                else if(l[i].r[0] == 'n') l[i].d = 1;
                else
                {
                    int x = get_num(l[i].l),y = get_num(l[i].r);
                    if(x > y) l[i].d = -INF;
                    else l[i].d = 0;
                }
            }
        }
        int ans = check();
        if(ans == -1) puts("ERR");
        else if(ans == 0) puts("No");
        else puts("Yes");
    }
    return 0;
}
