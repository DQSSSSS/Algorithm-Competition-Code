#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
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

char a[SZ],b[SZ];

int main() {
    int n = read();
    scanf("%s%s",a + 1,b + 1);
    LL ans = 0;
    for(int i = 1;i <= n;i ++) {
        if(i < n && a[i] != a[i + 1] && a[i] != b[i] && a[i + 1] != b[i + 1])
            swap(a[i],a[i + 1]),ans ++;
        if(a[i] != b[i]) ans ++,a[i] = b[i];
    }
    cout << ans << endl;
    return 0;
}
