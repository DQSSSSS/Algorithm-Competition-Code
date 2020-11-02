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
    node *ch[2],*f;
    int sz,v,cnt;

    void setc(node *x,int d) { (ch[d] = x) -> f = this; }
    void maintain() { sz = ch[0] -> sz + cnt + ch[1] -> sz; }
    int dir() { return f -> ch[1] == this; }
    int cmp(int x) { if(x == v) return -1; return x < v ? 0 : 1; }
    node(int x,node *fa);
}*root, *null;

node :: node(int x,node *fa) { v = x; sz = cnt = 1; f = fa; ch[0] = ch[1] = null; }

void rotate(node *p)
{
    node *fa = p -> f;
    int d = p -> dir();
    fa -> f -> setc(p,fa -> dir());
    fa -> setc(p -> ch[d ^ 1],d);
    p -> setc(fa,d ^ 1);
    fa -> maintain(); p -> maintain();
    if(fa == root) root = p;
}

void splay(node *p,node *rt = null)
{
    while(p -> f != rt)
    {
        if(p -> f -> f == rt) rotate(p);
        else
        {
            if(p -> dir() == p -> f -> dir()) rotate(p -> f),rotate(p);
            else rotate(p),rotate(p);
        }
    }
    p -> maintain();
}

void insert(node *p,int x)
{
    if(root == null) { root = new node(x,null); return ; }
    while(p != null)
    {
        p -> sz ++;
        int d = p -> cmp(x);
        if(d == -1) { p -> cnt ++; break; }
        if(p -> ch[d] == null)
        {
            p -> ch[d] = new node(x,p);
            p = p -> ch[d];
            break;
        }
        p = p -> ch[d];
    }
    splay(p);
}

void erase(node *p,int x)
{
    while(p != null)
    {
        p -> sz --;
        int d = p -> cmp(x);
        if(d == -1) { p -> cnt --; break; }
        p = p -> ch[d];
    }
    if(p -> cnt) return ;
    splay(p);
    if(root -> ch[0] == null) { root = root -> ch[1]; root -> f = null; return ; }
    if(root -> ch[1] == null) { root = root -> ch[0]; root -> f = null; return ; }
    p = p -> ch[0];
    while(p -> ch[1] != null) p = p -> ch[1];
    splay(p,root);
    p -> ch[1] = root -> ch[1]; p -> ch[1] -> f = p;
    p -> f = null; p -> maintain();
    delete root;
    root = p;
}

int ask_num(node *p,int k)
{
    while(p != null)
    {
        int l = p -> ch[0] -> sz + 1;
        int r = p -> ch[0] -> sz + p -> cnt;
        if(l <= k && k <= r) return p -> v;
        if(k > r) k -= r,p = p -> ch[1];
        else p = p -> ch[0];
    }
}

void init()
{
    null = new node(-INF,null);
    null -> sz = null -> cnt = 0;
    root = null;
}

int n,m;

int main()
{
    init();
    n = read(),m = read();
    int ans = 0,del = 0;
    for(int i = 1;i <= n;i ++)
    {
        char opt[3];
        scanf("%s",opt);
        int k = read();
        if(opt[0] == 'I')
        {
            if(k >= m) insert(root,k - del);
        }
        else if(opt[0] == 'A')
            del += k;
        else if(opt[0] == 'S')
        {
            del -= k;
            insert(root,m - del);
            ans += root -> ch[0] -> sz;
            root -> ch[0] = null;
            root -> maintain();
            erase(root,m - del);
        }
        else
            printf("%d\n",k > root -> sz ? -1 : (ask_num(root,root -> sz - k + 1) + del));
    }
    printf("%d\n",ans);
    return 0;
}
