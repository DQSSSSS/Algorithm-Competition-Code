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


int main() {
    int e = 200,p = 100,now = 100,sum = 1;
    for(int i = 1;i <= 100;i ++) {
        sum += now;
        int t = sum / e;
        sum -= t * e;
        now += t * p;
        printf("%9d%20d%9d%9d\n",sum,now,i,(1000000+now-1)/now);
    }
}
