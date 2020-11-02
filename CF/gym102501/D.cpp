#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 20010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
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

struct hahahaha {
    struct node {
        int l,r;
    }pool[SZ];

    vector<int> a;
    int tot = 1e4;

    int getNew(int l,int r) {
        pool[++ tot] = {l,r};
        return tot;
    }
    int getL(int x) {
        return pool[x].l;
    }
    int getR(int x) {
        return pool[x].r;
    }
    int ask_back() {
        return a[a.size()-1];
    }

    bool C() {
        a.push_back(ask_back());
        return true;
    }

    bool D() {
        a.pop_back();
        return true;
    }

    bool L() {
        int x = a.back();
        if(getL(x) == 0) return false;
        D(); a.push_back(getL(x));
        return true;
    }

    bool P() {
        int A = a.back(); D();
        int B = a.back(); D();
        a.push_back(getNew(A,B));
        return true;
    }

    bool R() {
        int x = a.back();
        if(getR(x) == 0) return false;
        D(); a.push_back(getR(x));
        return true;
    }

    bool S() {
        int A = a.back(); D();
        int B = a.back(); D();
        a.push_back(A);
        a.push_back(B);
        return true;
    }

    bool U() {
        int x = a.back(); D();
        if(getL(x) == 0) return false;
        if(getR(x) == 0) return false;
        a.push_back(getR(x));
        a.push_back(getL(x));
        return true;
    }

    bool work_char(char c) {
        if(c == 'C') return C();
        if(c == 'D') return D();
        if(c == 'L') return L();
        if(c == 'P') return P();
        if(c == 'R') return R();
        if(c == 'S') return S();
        if(c == 'U') return U();
    }

    bool work(char s[]) {
        int n = strlen(s);
        for(int i = 0;i < n;i ++) {
            if(!work_char(s[i]))
                return false;
        }
        return true;
    }

    void init() {
        for(int i = 1e4;i >= 1;i --) pool[i] = {0,0};
        for(int i = 1e4;i >= 1;i --) a.push_back(i);
    }
}a,b;

char s1[SZ],s2[SZ];

bool isLeaf(int u) {
    return u <= 1e4;
}

map<pii,int> mp;

bool dfs(hahahaha &a,hahahaha &b,int u,int v) {
    if(mp[{u,v}]) return mp[{u,v}];
    if(isLeaf(u) ^ isLeaf(v)) return mp[{u,v}] = false;
    if(isLeaf(u)) {
        return mp[{u,v}] = u == v;
    }
    return mp[{u,v}] = dfs(a,b,a.pool[u].l,b.pool[v].l) && dfs(a,b,a.pool[u].r,b.pool[v].r);
}

bool isEqu(hahahaha a,hahahaha b) {
    a.init();  b.init();
    bool b1 = a.work(s1);
    bool b2 = b.work(s2);
    if(b1 != b2) return false;
    if(!b1) return true;
    if(a.a.size() != b.a.size()) return false;
    for(int i = (int)a.a.size()-1;i >= 0;i --) {
        if(!dfs(a,b,a.a[i],b.a[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%s%s",s1,s2);

    puts(isEqu(a,b) ? "True" : "False");
}
