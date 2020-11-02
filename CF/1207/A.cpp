#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
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

int main() {
    int T = read();
    while(T --) {
        int b = read(),p = read(),f = read();
        int h = read(),c = read();
        int ans = 0;
        for(int i = 0;i <= 100;i ++) {
            for(int j = 0;j <= 100;j ++) {
                int bb = i * 2 + j * 2;
                int pp = i;
                int ff = j;
                if(bb <= b && pp <= p && ff <= f) {
                    ans = max(ans,i*h+j*c);
                }
            }
        }
        printf("%d\n",ans);
    }
}
