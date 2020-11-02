#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e6 + 10;
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

int n,a[SZ],b[SZ];

int work() {
    stack<int> s1,s2;
    for(int i = 1;i <= n;i ++) {
        int t1 = 0,t2 = 0;
        while(s1.size() && a[s1.top()] > a[i]) s1.pop(),t1 ++;
        while(s2.size() && b[s2.top()] > b[i]) s2.pop(),t2 ++;
        if(t1 != t2) return i - 1;
        s1.push(i);
        s2.push(i);
    }
    return n;
}

int main() {
    while(~scanf("%d",&n)) {
        for(int i = 1;i <= n;i ++) a[i] = read();
        for(int i = 1;i <= n;i ++) b[i] = read();
        printf("%d\n",work());
    }
}
