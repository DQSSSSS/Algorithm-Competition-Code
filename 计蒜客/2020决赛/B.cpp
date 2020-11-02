#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct haha {
    string name;
    LL v;
}a[SZ];

bool cmp(haha a,haha b) {
    return a.v<b.v;
}

char s[SZ];

int main() {
    int n = read();
    LL L = read();
    for(int i = 1;i <= n;i ++) {
        scanf("%s",s);
        a[i].name = s;
        a[i].v = read();
    }
    sort(a+1,a+1+n,cmp);
    for(int i = 1;i < n;i ++) {
        LL s = a[i].v * i;
        LL q = s / L, r = s % L;
        printf("%s %lld %lld\n",a[i].name.c_str(),q,L-r);
    }
    printf("%s",a[n].name.c_str());
}
