#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<double, double> pdd;
const int SZ = 2000100;
const LL INF = 1e18 + 10;
const int mod = 1e9+7;
const LD eps = 1e-6;

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
    for(int t = 1;;t ++) {
        system("data.exe");
        system("J.exe");
        system("JJ.exe");
        if(system("fc J.out std.out")){
            puts("WA");
            return 0;
        }
        else {
            printf("%d: AC\n",t);
        }
    }
}
