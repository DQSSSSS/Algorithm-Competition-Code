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
char opt[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    int now = 0,l = 1,r = n;
    int len = 0;
    while(l<=r) {
        if(a[l] <= now && a[r] <= now) break;
        if(l == r || (now < a[l] && (a[l] < a[r] || now >= a[r]))) now = a[l],opt[++len] = 'L',l ++;
        else if(now < a[r] && (a[r] < a[l] || now >= a[l])) now = a[r],opt[++len] = 'R',r --;
        else {
            int t1 = 1;
            for(int i = l;i < r;i ++)
                if(a[i] < a[i+1]) t1 ++;
                else break;
            int t2 = 1;
            for(int i = r;i > l;i --)
                if(a[i] < a[i-1]) t2 ++;
                else break;
            if(t1 <= t2) {
                while(t2--) opt[++ len] = 'R';
            }
            else {
                while(t1--) opt[++ len] = 'L';
            }
            break;
        }
    }
    printf("%d\n%s",len,opt+1);
}
