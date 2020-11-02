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

int lcp[SZ],sa[SZ],rk[SZ],len;


bool cmp(int *y,int a,int b,int k)
{
    int a1 = y[a],b1 = y[b];
    int a2 = a + k >= len ? -1 : y[a + k];
    int b2 = b + k >= len ? -1 : y[b + k];
    return a1 == b1 && a2 == b2;
}

int t1[SZ],t2[SZ],cc[SZ];

void get_sa(char s[])
{
    int *x = t1,*y = t2,m = 256;
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
            x[sa[i]] = cmp(y,sa[i - 1],sa[i],k) ? m - 1 : m ++;
        if(m >= len) break;
    }
}

void get_lcp(char s[])
{
    for(int i = 0;i < len;i ++) rk[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    for(int i = 0;i < len;i ++)
    {
        if(!rk[i]) continue;
        int j = sa[rk[i] - 1];
        if(h) h --;
        while(s[i + h] == s[j + h]) h ++;
        lcp[rk[i]] = h;
    }
}

int k;

bool check(int d)
{
    int x = 0;
    for(int i = 1;i < len;i ++)
    {
        if(lcp[i] >= d)
        {
            if(++ x >= k - 1) return true;
        }
        else x = 0;
    }
    return false;
}

int div()
{
    int l = 0,r = len + 1;
    while(r - l > 1)
    {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    return l;
}

char s[SZ];

int L[SZ],R[SZ],fa[SZ];

int find(int x)
{
    if(x == fa[x]) return x;
    int f = find(fa[x]);
    L[f] = min(L[f],L[x]); R[f] = max(R[f],R[x]);
    return fa[x] = f;
}

int main()
{
    int T = read();
    while(T --)
    {
        k = read();
        scanf("%s",s);
        len = strlen(s);
        get_sa(s); get_lcp(s);
        int max_len = div();
        for(int i = 0;i < len;i ++)
            L[i] = R[i] = fa[i] = i;
    /*    cout << max_len << endl;
        for(int i = 0;i < len;i ++) printf("%3d",sa[i]); puts("");
        for(int i = 0;i < len;i ++) printf("%3d",lcp[i]); puts("");
        puts("");
*/
        if(k == 1)
        {
            LL ans = 0;
            for(int d = max_len;d >= 1;d --)
            {
                for(int i = 1;i < len;i = R[find(i)] + 1)
                {
                    if(lcp[i] < d) continue;
                    int a = L[find(i)] - 1,b = i;
                    int x = find(a),y = find(b);
                    if(x != y)
                        fa[x] = y,L[y] = min(L[y],L[x]),R[y] = max(R[y],R[x]);
                }
                LL tmp = 0;
                for(int i = 0;i < len;i = R[find(i)] + 1)
                    if(R[find(i)] - L[find(i)] + 1 >= 2)
                        tmp ++;
                ans += tmp;
            }
            LL sum = 0;
            for(int i = 0;i < len;i ++)
                sum += len - sa[i] - lcp[i];
            printf("%I64d\n",sum - ans);
            continue;
        }
        LL ans = 0;
        for(int d = max_len;d >= 1;d --)
        {
            for(int i = 1;i < len;i = R[find(i)] + 1)
            {
                if(lcp[i] < d) continue;
                int a = L[find(i)] - 1,b = i;
                int x = find(a),y = find(b);
                if(x != y)
                    fa[x] = y,L[y] = min(L[y],L[x]),R[y] = max(R[y],R[x]);
            }
            LL tmp = 0;
            for(int i = 0;i < len;i = R[find(i)] + 1)
                if(R[find(i)] - L[find(i)] + 1 == k)
                    tmp ++;
            ans += tmp;
        //    for(int i = 0;i < len;i ++) printf("%3d",find(i)); puts("");
        //    cout << tmp << " " << d << endl;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

/*
233
1
abcddc

17

233
1
aaaaa

*/
