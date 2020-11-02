#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 500010;
const int mod = 998244353;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

LL f[1010];

int main() {
    f[1] = 1;
    f[2] = 1;
    for(int i = 3;i <= 50;i ++) {
        f[i] = f[i-1] +f[i-2];
        cout << i << " " << log2(f[i]&-f[i]);
        //for(int j = 30;j >= 0;j --)
        //    cout << (f[i] >> j & 1);
        puts("");
    }
    return 0;
}
