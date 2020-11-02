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

int a[SZ],n,k;

bool check() {
    int x = 0;
    int L = 0,R = n+1;
    while(R-L>1) {
        int mid = L + R >> 1;
        if(1ll * (2*mid+k-1) * k / 2 <= n) L = mid;
        else R = mid;
    }
    x = L;
    if(x == 0) return false;
    for(int i = 1;i <= k;i ++) a[i] = x + i - 1,n -= a[i];
   // cout << n << endl;
    //for(int i = 1;i <= k;i ++) printf("%d ",a[i]); puts("");
    while(n) {
        int x = 0;
        int L = 0,R = n+1;
        while(R-L>1) {
            int mid = L + R >> 1;
            if(1ll * (1+mid) * mid / 2 <= n) L = mid;
            else R = mid;
        }
        x = L;
        n -= x * (x+1) / 2;
  //      cout << x<< endl;
        for(int i = k-x+1,j = 1;i <= k;i ++) a[i] += j++;
    }
//    for(int i = 1;i <= k;i ++) printf("%d ",a[i]); puts("");
    for(int i = 1;i < k;i ++)
        if(!(a[i] < a[i+1] && a[i+1] <= 2*a[i]))
            return false;
    return true;
}

int main() {
    n = read(),k = read();
    bool flag = check();
    if(!flag) puts("NO");
    else {
        puts("YES");
        for(int i = 1;i <= k;i ++) printf("%d ",a[i]); puts("");
    }
/*
    int cc = 0;
    for(int nn = 1e9-10000;nn <= 1e9;nn ++) {
        //n = read(),k = read();
        for(int kk = 1;kk <= 10000;kk ++) {
            n = nn; k = kk;
            bool flag = check();

            cc ++;
            //if(cc % 10000 == 0)
                cout << cc << endl;

        }
    }*/
}
