#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 200010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;

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
    int T = read(),cc = 0;
    while(T --) {
        int n = read(),k = 0,r = 0,c = 0;
        map<int,int> mp[1110],mp2[1110];
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= n;j ++) {
                int x = read();
                if(i == j) k += x;
                if(!mp[i].count(x)) mp[i][x] = 1;
                if(!mp2[j].count(x)) mp2[j][x] = 1;
            }
        }
        for(int i = 1;i <= n;i ++) {
            if(mp[i].size() != n) r ++;
            if(mp2[i].size() != n) c ++;
        }
        printf("Case #%d: %d %d %d\n",++ cc,k,r,c);
    }
}
