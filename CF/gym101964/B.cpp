#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 1e5 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 +a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}


int main() {
    ULL a = read(),b = read(),c = read(),n = read();
    ULL ans;
    if(n & 1) {
        ULL x = n / 2;
        ans = x * (x + 1);
    }
    else {
        ULL x = n / 2;
        ans = x * (x + 1) - 2 + (x-1) * 2;
    }
    if(a == b && b == c) {
        if(n % 2 == 0) n /= 2;
        else if(ans % 2 == 0) ans /= 2;
        if(n % 3 == 0) n /= 3;
        else if(ans % 3 == 0) ans /= 3;
    }
    else if(a == b || a == c || b == c) {
        if(n % 2 == 0) n /= 2;
        else if(ans % 2 == 0) ans /= 2;
    }
    ans *= n;
    cout << ans << endl;
}
