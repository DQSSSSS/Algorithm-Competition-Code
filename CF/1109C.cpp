#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 3e5 + 10;
const int mod = 998244353;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct node {
    node *ch[2],*f;
    LL time,timel,timer,sz;
    LL res,minn,speedr,speed;

    void setc(node *x,int d) { (ch[d] = x) -> f = this; }

    void maintain();

    int dir() { return f -> ch[1] == this; }
    int cmp(int v) { if(v == time) return -1; return v < time ? 0 : 1; }
} *root, *null, T[SZ];

int Tcnt1,Tcnt2,S[SZ];

node* newnode(int t,LL s) {
    node *p;
    if(Tcnt2) p = T + S[Tcnt2 --];
    else p = T + (++ Tcnt1);
    p -> ch[0] = p -> ch[1] = p -> f = null;
    p -> time = p -> timel = p -> timer = t;
    p -> speed = p -> speedr = s;
    p -> minn = p -> res = 0;
    p -> sz = 1;
    return p;
}

void print(node *p) {
    printf("%lld %lld-> res:%lld minn:%lld  speedr:%lld\n",p->time,p->speed,p->res,p->minn,p->speedr);
}

void dfs(node *p,int d = 0) {
    if(p == null) return ;
    for(int i = 1;i <= d;i ++) cout << "\t"; print(p);
    for(int i = 1;i <= d;i ++) cout << "\t"; cout << "lc : ";puts("");
    dfs(p->ch[0],d+1);
    for(int i = 1;i <= d;i ++) cout << "\t"; cout << "rc : ";puts("");
    dfs(p->ch[1],d+1);
}

void node :: maintain() {
    if(this == null) return ;
    sz = ch[0] -> sz + 1 + ch[1] -> sz;
    if(ch[0] == null && ch[1] == null) {
        res = minn = 0;
        return ;
    }
    else if(ch[0] == null) {
        timel = ch[1] -> timel;
        timer = ch[1] -> timer;
        minn = min(0ll,ch[1] -> minn);
        res = speed * (ch[1] -> timel - time);
        minn = min(minn,res + ch[1] -> minn);
        res += ch[1] -> res;
        minn = min(minn,res);
    }
    else if(ch[1] == null) {
        timel = ch[0] -> timel;
        timer = ch[0] -> timer;
        minn = min(0ll,ch[0] -> minn);
        res = ch[0] -> res + ch[0] -> speedr * (time - ch[0] -> timer);
        minn = min(minn,res);
    }
    else {
        timel = ch[0] -> timel;
        timer = ch[1] -> timer;
        minn = min(0ll,ch[0] -> minn);
        res = ch[0] -> res;

        res += ch[0] -> speedr * (time - ch[0] -> timer);
        minn = min(minn,res);
        res += speed * (ch[1] -> timel - time);
        minn = min(minn,res + ch[1] -> minn);
        res += ch[1] -> res;
        minn = min(minn,res);
    }
}

void rotate(node *p) {
    node *fa = p -> f;
    int d = p -> dir();
    fa -> f -> setc(p,fa -> dir());
    fa -> setc(p -> ch[d ^ 1],d); fa -> maintain();
    p -> setc(fa,d ^ 1); p -> maintain();
    if(fa == root) root = p;
}

void splay(node *p,node *rt = null) {
    p -> maintain();
    while(p -> f != rt) {
        if(p -> f -> f == rt) rotate(p);
        else {
            if(p -> dir() == p -> f -> dir())
                rotate(p->f),rotate(p);
            else
                rotate(p),rotate(p);
        }
    }
    p -> maintain();
}

void insert(int t,int s) {
    node *p = root;
    while(p != null) {
        int d;
        if(t > p -> time) d = 1;
        else d = 0;
        if(p -> ch[d] == null) {
            p -> setc(newnode(t,s),d);
            p -> maintain();
            p = p -> ch[d];
            break;
        }
        p = p -> ch[d];
    }
    node *pp = p;
    while(p != null) p -> maintain(),p = p -> f;
    splay(pp);
}

void erase(int t) {
    node *p = root;
    while(p != null) {
        int d;
        if(t > p -> time) d = 1;
        else d = 0;
        if(p -> ch[d] -> time == t) {
            S[++ Tcnt2] = p - T;
            p -> ch[d] = null;
            p -> maintain();
            break;
        }
        p = p -> ch[d];
    }
    while(p != null) p -> maintain(),p = p -> f;
}

node* find(int v) {
    node *p = root,*ans;
    while(p != null) {
        if(v == p -> time) return p;
        if(v <= p -> time) ans = p,p = p -> ch[0];
        else p = p -> ch[1];
    }
    return ans;
}

double ask(int l,int r,LL v) {
    if(v == 0) return l;
    splay(find(l-1)); splay(find(r+1),root);
    node *p = root -> ch[1] -> ch[0];
    if(p == null) return -1;
    dfs(p);

    while(p -> ch[0] != null || p -> ch[1] != null) {
        if(p -> ch[0] != null) {
            if(p -> ch[0] -> minn + v <= 0) {
                p = p -> ch[0];
                continue;
            }
            v += p -> ch[0] -> res;
            if(v + p -> ch[0] -> speedr * (p -> time - p -> ch[0] -> timer) <= 0) {
                return p -> ch[0] -> timer + 1.0*v/abs(p->ch[0]->speedr);
            }
            v += p -> ch[0] -> speedr * (p -> time - p -> ch[0] -> timer);
        }

        if(p -> ch[1] != null) {
            if(v + p -> speed * (p -> ch[1] -> timel - p -> time) <= 0)
                return p -> time + 1.0*v/abs(p->speed);
            v += p -> speed * (p -> ch[1] -> timel - p -> time);
            if(v + p -> ch[1] -> minn <= 0) {
                p = p -> ch[1];
                continue;
            }
        }
        break;
    }
    if(v + p -> speedr * (r - p -> timer) <= 0)
        return p -> timer + 1.0*v/abs(p->speedr);
    return -1;
}

void init() {
    null = newnode(0,0); null -> sz = 0;
    root = newnode(0,0);
    root -> setc(newnode(1e9+1,0),1);
}

int main() {
    init();
    int q = read();
    while(q --) {
        int opt = read();
        if(opt == 1) {
            int t = read(),s = read();
            insert(t,s);
        }
        else if(opt == 2) {
            int t = read();
            erase(t);
        }
        else {
            int l = read(),r = read(),v = read();
            double ans = ask(l,r,v);
            if(ans < 0 || ans > r) puts("-1");
            else printf("%.7f\n",ans);
        }
                    dfs(root); puts("---");

    }
}
