#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 5000 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}


const int mod1 = 1000189471;
const int mod2 = 1000056479;
struct HASH {
    int a,b;
    HASH(LL x,LL y) {a=x; b=y;}
    HASH(int x,int y) {a=x; b=y;}
    HASH(int x) {a=b=x;}
    HASH() {a=b=0;}
};

const HASH BASE = HASH(1313131,100007);

HASH operator *(const HASH &a,const HASH &b) {
    return HASH(1ll*a.a*b.a%mod1,1ll*a.b*b.b%mod2);
}

HASH operator +(const HASH &a,const HASH &b) {
    return HASH((a.a+b.a)%mod1,(a.b+b.b)%mod2);
}

bool operator <(const HASH &a,const HASH &b) {
    if(a.a != b.a) return a.a < b.a;
    return a.b < b.b;
}

bool operator ==(const HASH &a,const HASH &b) {
    if(a.a != b.a) return false;
    return a.b == b.b;
}

int str[SZ];
vector<HASH> g[SZ];

void work(int x,int maxlen) {
    int &len = str[0];
    int id = -1;
    for(int i = 1;i <= len;i ++) {
        if(str[i] == x) {
            id = i;
            break;
        }
    }
    if(id == -1) {
        len ++;
        for(int i = len;i >= 2;i --) str[i] = str[i-1];
        str[1] = x;
    }
    else {
        for(int i = id;i >= 2;i --) str[i] = str[i-1];
        str[1] = x;
    }
    HASH h = 0;
   // for(int i = 1;i <= len;i ++) cout << str[i] << " "; puts("");
    for(int i = 1;i <= maxlen;i ++) {
        h = h * BASE + str[i];
        g[i].push_back(h);
    }
}

struct haha {
    int id;
    HASH h;
    bool ans;
    int len;
}b[SZ];

bool cmp(haha &a,haha &b) {
    return a.len < b.len;
}
bool cmp2(haha &a,haha &b) {
    return a.id < b.id;
}

int opt[SZ];

int main() {
    for(int i = 1;i <= 5000;i ++) str[i] = 1,g[i].clear();
    str[0] = 0;
    int T = read();
    while(T --) {
        int n = read(),m = read();

        int maxlen = 0;
        for(int i = 1;i <= n;i ++) {
            opt[i] = read() + 1;
        }
        for(int i = 1;i <= m;i ++) {
            b[i].len = read();
            b[i].id = i;
            HASH h = 0;
            for(int j = 1;j <= b[i].len;j ++) {
                int x = read() + 1;
                h = h * BASE + x;
            }
            b[i].h = h;
            maxlen = max(maxlen,b[i].len);
        }
        sort(b+1,b+1+m,cmp);

        for(int i = 1;i <= n;i ++) {
            int x = opt[i];
            work(x,maxlen);
        }

        HASH h = 0;
        for(int i = 1;i <= maxlen;i ++) {
            h = h * BASE + 1;
            g[i].push_back(h);
        }

        for(int i = 1,j = 1;i <= m;i ++) {
            if(i == m || b[i].len != b[i+1].len) {
                int l = b[i].len;
                sort(g[l].begin(),g[l].end());
                while(j <= i) {
                    auto it = lower_bound(g[l].begin(),g[l].end(),b[j].h);
                    if(it != g[l].end() && *it == b[j].h) b[j].ans = 1;
                    else b[j].ans = 0;
                    j ++;
                }
            }
        }
        sort(b+1,b+1+m,cmp2);
        for(int i = 1;i <= m;i ++) {
            puts(b[i].ans ? "Yes" : "No");
        }

        for(int i = 1;i <= str[0];i ++) str[i] = 1;
        for(int i = 1;i <= maxlen;i ++) g[i].clear();
        str[0] = 0;
    }
}
/*
344
7 5
4 3 4 2 3 1 4
1 4
2 2 3
3 3 2 1
4 4 1 3 2
4 0 0 0 0

10 1
1 2 3 4 5 6 7 8 9 10
1 1

7 6
7 6 5 4 3 2 1
1 0
4 2 4 5 3
1 1
3 2 4 1
4 2 4 1 0
10 3 4 5 6 7 0 0 0 0 0

1 5
1
5 1 0 0 0 0
2 1 0
3 1 0 0
1 1
4 0 0 0 7

7 5
4 3 4 2 3 1 4
1 4
2 2 3
3 3 2 1
4 4 1 3 2
4 0 0 0 0

*/
