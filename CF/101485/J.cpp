#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e5 + 10;
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

int get(int x) {
    for(int i = 0;i <= 255;i ++) {
        if((i^((i<<1)&255)) == x) return i;
    }
}

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        int x = read();
        printf("%d ",get(x));
    }
}
