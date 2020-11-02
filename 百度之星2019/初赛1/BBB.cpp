#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

int get(int a,int b) {
    int len = abs(a-b);
    return (len+1) / 2;
}

struct haha {
    int p,d;
}c[111];

const int B = 10;

void moveto(int L,int R) {
    printf("[%d,%d]\n",L,R);
    pii p = make_pair(L,R);
    if(c[0].p == -1) {
        for(int i = 0;i < B;i ++) c[i].p=min(p.first+i,p.second);
        for(int i = 0;i < B;i ++) c[i+B].p=max(p.first,p.second-i);
    }
    else {
        haha d[2*B];
        for(int i = 0;i < B;i ++) d[i].p=min(p.first+i,p.second);
        for(int i = 0;i < B;i ++) d[i+B].p=max(p.first,p.second-i);

        for(int i = 0;i < 2*B;i ++) {
            d[i].d = INF;
            for(int j = 0;j < 2*B;j ++) {
                d[i].d = min(d[i].d,c[j].d+get(c[j].p,d[i].p));
            }
        }
        for(int i = 0;i < 2*B;i ++) c[i] = d[i];
    }
}

pii a[SZ];

int main() {
  //  freopen("B.in","r",stdin); freopen("my.out","w",stdout);
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 0;i < 2*B;i ++) c[i].p = -1,c[i].d = 0;
        int L = 1,R = 1e6;
        for(int k = 1;k <= n;k ++) {
            int l = read(),r = read();
            if(max(L,l) + 2*B > min(r,R)) {
                moveto(L,R);

                L = l; R = r;
                if(k == n) {
                    moveto(l,r);
                }
            }
            else {
                L = max(L,l);
                R = min(R,r);
                if(k == n) {
                    moveto(L,R);
                }
            }
            //for(int i = 0;i < 2*B;i ++) printf("%d %d\n",c[i].p,c[i].d);
           // puts("------");
        }

        int ans = INF;
        for(int i = 0;i < 2*B;i ++) ans = min(ans,c[i].d);
        printf("%d\n",ans);
    }
}
/**

1
7
8 10
11 12
23 23
24 24
11 14
17 24
2 6

[8,10]
[11,12]
[23,23]
[24,24]
[11,14]
[17,24]
[2,6]
21

*/
