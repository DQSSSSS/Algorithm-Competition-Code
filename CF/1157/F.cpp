#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 8e6 + 10;
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

int a[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[read()] ++;
    int ans = 1;
    for(int i = 1,j;i <= 2e5;i ++) {
        if(a[i] && a[i+1]) ans = max(ans,a[i]+a[i+1]);
        if(a[i]) ans = max(ans,a[i]);
        if(a[i] >= 2) {
            int sum = 0;
            for(j = i;a[j] >= 2;j ++) sum += a[j];
            ans = max(ans,sum + a[i-1] + a[j]);
            i = j;
        }
    }

    printf("%d\n",ans);
    for(int i = 1,j;i <= 2e5;i ++) {
        if(a[i] && a[i+1]) {
            if(ans == a[i]+a[i+1]) {
                while(a[i] --) printf("%d ",i);
                while(a[i+1] --) printf("%d ",i+1);
                break;
            }
        }
        if(a[i]) {
            if(ans == a[i]) {
                while(a[i] --) printf("%d ",i);
                break;
            }
        }
        if(a[i] >= 2) {
            int sum = 0;
            for(j = i;a[j] >= 2;j ++) sum += a[j];
            if(ans == sum + a[i-1] + a[j]) {
                while(a[i-1] --) printf("%d ",i-1);
                for(j = i;a[j] >= 2;j ++) {
                    while(a[j] > 1) printf("%d ",j),a[j] --;
                }
                while(a[j] --) printf("%d ",j);
                for(j --;j >= i;j --) {
                    int x = a[j];
                    while(x --) printf("%d ",j);
                }
                break;
            }
            i = j;
        }
    }
}
