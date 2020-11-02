#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

typedef long long LL;
const int SZ = 200005;
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

int ch[SZ][26];
int par[SZ];
int val[SZ];
int last,sz[SZ],Tcnt = 0,root;

void get(int k,int x)
{
    memset(ch[k],0,sizeof(ch[k]));
    val[k] = x;
    par[k] = 0;
    sz[k] = 0;
}

void insert(int x)
{
    int p = last,np = ++ Tcnt;
    get(np,val[last] + 1);
    while(p && !ch[p][x])
        ch[p][x] = np,p = par[p];
    if(!p)
        par[np] = root;
    else
    {
        int q = ch[p][x];
        if(val[q] == val[p] + 1)
            par[np] = q;
        else
        {
            int nq = ++ Tcnt;
            get(nq,val[p] + 1);
            memcpy(ch[nq],ch[q],sizeof(ch[q]));
            par[nq] = par[q];
            par[np] = par[q] = nq;
            while(p && ch[p][x] == q)
                ch[p][x] = nq,p = par[p];
        }
    }
    last = np;
    sz[np] = 1;
}


void init()
{
    Tcnt = 1; root = 1;
    get(1,0);
    last = root;
}

char s[100010];


vector<int> g[SZ];

void build(int f,int t)
{
    g[f].push_back(t);
}

void dfs(int u)
{
    for(int i = 0;i < g[u].size();i ++)
        dfs(g[u][i]),sz[u] += sz[g[u][i]];
}

int main()
{
    int T = read();
    while(T --)
    {
        memset(sz,0,sizeof(sz));
        init();
        int k = read();
        scanf("%s",s);
        int len = strlen(s);
        for(int i = 0;i < len;i ++)
            insert(s[i] - 'a');

        for(int i = 0;i <= Tcnt;i ++) g[i].clear();
        for(int i = 1;i <= Tcnt;i ++)
            build(par[i],i);
        dfs(0);
        LL ans = 0;
        for(int i = 0;i <= Tcnt;i ++)
            if(sz[i] == k) ans += val[i] - val[par[i]];
    //    for(int i = 1;i < Tcnt;i ++) cout << ::T[i].sz << " "; puts("");
        cout << ans << endl;
    }
    return 0;
}

/*
2
2
abcabc
3
abcabcabcabc

*/
