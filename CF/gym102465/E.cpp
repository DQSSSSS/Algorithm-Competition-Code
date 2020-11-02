#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
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

string str[SZ];
int a[SZ],L[SZ],R[SZ];

char s[SZ];

int main() {
    int n = read();
    int sum = 0;
    int t100 = 0,t0 = 0;
    for(int i = 1;i <= n;i ++) {
        scanf("%s",s);
        str[i] = s;
        a[i] = read() * 100;
        sum += a[i];
        if(a[i] == 10000) t100 ++;
        if(a[i] == 0) t0 ++;
    }

    for(int i = 1;i <= n;i ++) L[i] = a[i] == 0 ? 0 : -50;
    for(int i = 1;i <= n;i ++) R[i] = a[i] == 10000 ? 0 : 49;
    for(int i = 1;i <= n;i ++) {
        int t;
        if(a[i] == 10000) t = n - t100;
        else t = n - 1 - t100;
        int tmp = sum + 49 * t;
        L[i] = max(L[i],10000-tmp);
    }

    for(int i = 1;i <= n;i ++) {
        int t;
        if(a[i] == 0) t = n - t0;
        else t = n - 1 - t0;
        int tmp = sum - 50 * t;
        R[i] = min(R[i],10000 - tmp);
    }

   // for(int i = 1;i <= n;i ++) cout << L[i] << " "; puts("");
    //for(int i = 1;i <= n;i ++) cout << R[i] << " "; puts("");
    for(int i = 1;i <= n;i ++) {
        if(L[i] > R[i]) {
            puts("IMPOSSIBLE");
            return 0;
        }
    }

    for(int i = 1;i <= n;i ++) {
        int l = a[i] + L[i];
        int r = a[i] + R[i];
        printf("%s %d.%02d %d.%02d\n",str[i].c_str(),l/100,l%100,r/100,r%100);
    }
    return 0;
}
