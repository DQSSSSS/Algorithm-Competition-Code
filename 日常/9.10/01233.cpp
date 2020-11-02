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

struct sam_node{
    sam_node *par,*ch[26];
    int val;
}T[SZ], *root, *last;

int Tcnt = 0;
int sz[SZ];

sam_node* newnode(int x)
{
    sam_node *k = T + (Tcnt ++);
    k -> val = x;
    memset(k -> ch,0,sizeof(k -> ch));
    k -> par = 0;
    return k;
}

void insert(int x)
{
    sam_node *p = last,*np = newnode(last -> val + 1);
    while(p && !p -> ch[x])
        p -> ch[x] = np,p = p -> par;
    if(!p)
        np -> par = root;
    else
    {
        sam_node *q = p -> ch[x];
        if(q -> val == p -> val + 1)
            np -> par = q;
        else
        {
            sam_node *nq = newnode(p -> val + 1);
            memcpy(nq -> ch,q -> ch,sizeof(q -> ch));
            nq -> par = q -> par;
            np -> par = q -> par = nq;
            while(p && p -> ch[x] == q)
                p -> ch[x] = nq,p = p -> par;
        }
    }
    last = np;
    sz[np - T] = 1;
}


void init()
{
    Tcnt = 0;
    root = newnode(0);
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

        for(int i = 0;i < Tcnt;i ++) g[i].clear();
        for(int i = 1;i < Tcnt;i ++)
        {
            sam_node* p = ::T + i;
            build(p -> par - :: T,i);
        }
        dfs(0);
        LL ans = 0;
        for(int i = 1;i < Tcnt;i ++)
        {
            sam_node* p = ::T + i;
            if(sz[i] == k) ans += p -> val - p -> par -> val;
        }
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
