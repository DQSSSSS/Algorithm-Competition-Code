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

int f[SZ];

int main() {
    memset(f,-1,sizeof f);
    f[0] = 0;
    for(int i = 1;i <= 100;i ++) {
    //    if(f[i] != -1) continue;
        int a[] = {1,2,5,10},ans = INF,c;
        for(int j = 0;j < 4;j ++) {
            int x = a[j];
            if(i>=x && f[i-x]+1 < ans) {
                ans = f[i-x] + 1;
                c = x;
            }
        }
        f[i] = ans;
        printf("%d %d %d\n",i,ans,c);
    }
}
