#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 5e4 + 10;
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

mt19937 rd(time(0));

int randlr(int l,int r) {
    return rd()%(r-l+1)+l;
}

int main() {
    freopen("J.in","w",stdout);
    int T = 3;
    printf("%d\n",T);
    while(T --) {
        int n = randlr(3,1000);
        printf("%d\n",n);
        map<pii,int> mp;
        int B = 20;
        for(int i = 1;i <= n;i ++) {
            int x = randlr(-B,B);
            int y = randlr(-B,B);
            pii p = make_pair(x,y);
            while(mp.count(p)) {
                x = randlr(-B,B);
                y = randlr(-B,B);
                p = make_pair(x,y);
            }
            mp[p] = 1;
            printf("%d %d\n",x,y);
        }
    }
}
