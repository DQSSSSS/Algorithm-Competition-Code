#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 5000010;
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

int main() {
    for(int t = 1;;t ++) {
        system("test.exe");
        system("F.exe");
        cout << t << endl;
    }
}
