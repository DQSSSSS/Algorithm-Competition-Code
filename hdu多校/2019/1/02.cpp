#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 8e6 + 10;
const int INF = 1e9 + 10;
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

struct seg {
    int a[31];
    seg() { memset(a,0,sizeof a); }
};

void build(seg root,)

int main() {
    int T = read();
    while(T --) {
        n = read(),m = read();
        for(int i = 1;i <= n;i ++) {
            a[i] = read();
        }
        int len = n;
        for(int i = 1;i <= m;i ++) {
            opt[i] = read();
            if(opt[i] == 0) L[i] = read(),R[i] = read();
            else val[i] = read(),len ++;
        }
        seg root;
        build(root,1,len);
        int nown = n,lstans = 0;
        for(int i = 1;i <= m;i ++) {
            int o = opt[i];
            if(o == 0) {
                int l = (L[i] ^ lstans) % nown + 1;
                int r = (R[i] ^ lstans) % nown + 1;
                if(l > r) swap(l,r);
                lstans = ask(root,1,len,l,r);
                printf("%d\n",lstans);
            }
            else {
                nown ++;
                int x = val[i] ^ lstans;
                change(root,1,len,nown,x);
            }
        }
        gc(root,1,len);
    }
}
