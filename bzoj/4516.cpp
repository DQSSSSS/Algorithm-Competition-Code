#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

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

struct node
{
    map<int,node*> ch;
    node *par;
    int val;
    node(int x) { val = x; par = NULL; ch.clear(); }
}*root,*last;

LL ans = 0;

LL get_ans(node *p)
{
    return p -> val - p -> par -> val;
}

void insert(int x)
{
    node *p = last,*np = new node(last -> val + 1);
    while(p && !p -> ch[x])
        p -> ch[x] = np,p = p -> par;
    if(!p)
        np -> par = root,ans += get_ans(np);
    else
    {
        node *q = p -> ch[x];
        if(q -> val == p -> val + 1)
            np -> par = q,ans += get_ans(np);
        else
        {
            node *nq = new node(p -> val + 1);
            nq -> ch = q -> ch;
            nq -> par = q -> par;
            ans += get_ans(nq);
            
            ans -= get_ans(q);
            q -> par = np -> par = nq;
            ans += get_ans(q) + get_ans(np);
            while(p && p -> ch[x] == q)
                p -> ch[x] = nq,p = p -> par;
        }
    }
    last = np;
}

void init()
{
    root = new node(0);
    last = root;
}

int main()
{
    init();
    int n = read();
    for(int i = 1;i <= n;i ++)
    {
        int x = read();
        insert(x);
        printf("%lld\n",ans);
    }
    return 0;
}
