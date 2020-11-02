#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
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

bool cmp(pii a,pii b) {
    return a.second < b.second;
}

pii a[SZ];

int main() {
    int n = read(),m = read(),k = read();
    for(int i = 1;i <= n;i ++) {
        a[i].first = -read();
        a[i].second = i;
    }
    sort(a + 1,a + 1 + n);
    sort(a + 1,a + 1 + k * m,cmp);
    LL sum = 0;
    for(int i = 1;i <= k * m;i ++) sum += a[i].first;
    cout << -sum << endl;
    //for(int i = 1;i <= k * m;i ++) cout << a[i].first << " " << a[i].second <<endl;
    for(int i = 1;i < k * m;i ++) {
        if(i % m == 0)
            printf("%d ",a[i].second);
    }
}
