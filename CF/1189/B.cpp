#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1073741823 + 10;
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
    for(int i = 0;i < n;i ++) a[i] = read();
    sort(a,a+n);
    int flag = 0;
    for(int i = 0;i < n;i ++) {
        int l = i==0 ? n-1 : i-1;
        int r = i==n-1 ? 0 : i+1;
        if(a[i] >= a[l]+a[r]) flag = 1;
    }
    if(flag) {
        swap(a[n-1],a[n-2]);
        flag = 0;
        for(int i = 0;i < n;i ++) {
            int l = i==0 ? n-1 : i-1;
            int r = i==n-1 ? 0 : i+1;
            if(a[i] >= a[l]+a[r]) flag = 1;
        }
        if(flag) puts("NO");
        else {
            puts("YES");
            for(int i = 0;i < n;i ++)
                printf("%d ",a[i]);
        }
    }
    else {
        puts("YES");
        for(int i = 0;i < n;i ++)
            printf("%d ",a[i]);
    }
}

