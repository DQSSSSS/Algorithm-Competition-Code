#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

int main() {
    int n = read();
    int l = 0,r = 1e9,t = 0;
    while(r - l > 1) {
        int mid = l + r >> 1;
        printf("> %d\n",mid); fflush(stdout);
        t ++;
        int rt = read();
        if(rt == 0) r = mid;
        else l = mid;
    }
    int maxn = r;
    mt19937 randint(time(0));
    vector<int> a;
    map<int,bool> id;
    for(int i = 1;i <= min(60 - t,n);i ++) {
        int x = randint() % n + 1;
        while(id[x]) x = randint() % n + 1;
        id[x] = 1;
        printf("? %d\n",x); fflush(stdout);
        int d = read();
        a.push_back(d);
    }
    int d = 0;
    for(int i = 0;i < a.size();i ++)
        for(int j = 0;j < a.size();j ++)
            d = __gcd(d,a[i] - a[j]);
    if(d < 0) d = -d;
    int x1 = maxn - d * (n - 1);
    printf("! %d %d",x1,d);
    return 0;
}
