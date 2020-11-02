#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
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


int lcp[SZ],sa[SZ],rank[SZ],len,n;


bool cmp_sa(int *y,int a,int b,int k)
{
    int a1 = y[a],b1 = y[b];
    int a2 = a + k >= len ? -1 : y[a + k];
    int b2 = b + k >= len ? -1 : y[b + k];
    return a1 == b1 && a2 == b2;
}

int t1[SZ],t2[SZ],cc[SZ];

void get_sa(int s[])
{
    int *x = t1,*y = t2,m = 100000;
    for(int i = 0;i < m;i ++) cc[i] = 0;
    for(int i = 0;i < len;i ++) ++ cc[x[i] = s[i]];
    for(int i = 1;i < m;i ++) cc[i] += cc[i - 1];
    for(int i = len - 1;~i;i --) sa[-- cc[x[i]]] = i;
    for(int k = 1;k < len;k <<= 1)
    {
        int p = 0;
        for(int i = len - k;i < len;i ++)  y[p ++] = i;
        for(int i = 0;i < len;i ++) if(sa[i] >= k) y[p ++] = sa[i] - k;
        for(int i = 0;i < m;i ++) cc[i] = 0;
        for(int i = 0;i < len;i ++) ++ cc[x[y[i]]];
        for(int i = 1;i < m;i ++) cc[i] += cc[i - 1];
        for(int i = len - 1;~i;i --) sa[-- cc[x[y[i]]]] = y[i];
        swap(x,y); m = 1; x[sa[0]] = 0;

        for(int i = 1;i < len;i ++)
            x[sa[i]] = cmp_sa(y,sa[i - 1],sa[i],k) ? m - 1 : m ++;
        if(m >= len) break;
    }
}

void get_lcp(int s[])
{
    for(int i = 0;i < len;i ++) rank[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    for(int i = 0;i < len;i ++)
    {
        if(!rank[i]) continue;
        int j = sa[rank[i] - 1];
        if(h) h --;
        while(s[i + h] == s[j + h]) h ++;
        lcp[rank[i]] = h;
    }
}

stack<int> S;
bool use[SZ];
int id[SZ];

bool check(int d)
{
    while(S.size()) use[S.top()] = 0,S.pop();

    use[id[sa[0]]] = 1;
    S.push(id[sa[0]]);
    int ans = 1;
    for(int i = 1;i < len;i ++)
    {
        if(lcp[i] >= d)
        {
            int x = id[sa[i]];
            if(!use[x]) use[x] = 1,ans ++,S.push(x);
            if(ans > n / 2) return true;
        }
        else
        {
            while(S.size()) use[S.top()] = 0,S.pop();
            ans = 1;
            use[id[sa[i]]] = 1;
            S.push(id[sa[i]]);
        }
    }
    return false;
}

int div()
{
    int l = 1,r = len + 1;
    while(r - l > 1)
    {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    return l;
}

char str[SZ];
int s[SZ];
int tot = 0,sans[SZ];

void get(int d)
{
    tot = 0;
    bool flag = 0;
    if(lcp[1] >= d)
        sans[++ tot] = sa[0],flag = 1;
    for(int i = 1;i < len;i ++)
    {
        if(lcp[i] >= d)
        {
            if(!flag) flag = 1,sans[++ tot] = sa[i];
        }
        else
        {
            flag = 0;
            if(lcp[i + 1] >= d) sans[++ tot] = sa[i],flag = 1;
        }
    }
}

int ans;

bool cmp(int a,int b)
{
    for(int i = a,j = b;i < a + ans;i ++,j ++)
        if(s[i] != s[j])
            return s[i] < s[j];
    return false;
}

int main()
{
    bool first = 1;
    while(~scanf("%d",&n) && n)
    {
        len = 0;
        for(int i = 1,fg = 200;i <= n;i ++)
        {
            scanf("%s",str);
            int l = len,m = strlen(str);
            for(int j = l;j < l + m;j ++) //aaaaabbbb
                id[j] = i,s[j] = str[j - l];
            s[l + m] = fg ++;
            len += m + 1;
        }
        get_sa(s); get_lcp(s);


    /*    for(int i = 0;i < len;i ++) printf("%4d",s[i]); puts("");
        for(int i = 0;i < len;i ++) printf("%4d",sa[i]); puts("");
        for(int i = 0;i < len;i ++) printf("%4d",lcp[i]); puts("");
*/
        if(first) puts(""),first = 0;
        ans = div();
        if(ans == 1) { puts("?"); continue;}
        get(ans);

        sort(sans + 1,sans + 1 + tot,cmp);

        for(int i = 1;i <= tot;i ++,puts(""))
        {
            for(int j = sans[i];j < sans[i] + ans;j ++)
                printf("%c",s[j]);
        }
    }
    return 0;
}
