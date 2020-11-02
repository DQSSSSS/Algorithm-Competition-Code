#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 4e5 + 10;
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

int num[SZ],t[SZ];

int main() {
    int n = read(),m = read();
    int sum = 0,minn = 0;
    num[0] = n;
    for(int i = 1;i <= m;i ++) {
        int x = read();
        num[t[x]] --;
        int ans = 0;
        if(minn == t[x] && num[t[x]] == 0)
            minn ++,ans = 1;
        t[x] ++;
        num[t[x]] ++;
        printf("%d",ans);
    }
}
