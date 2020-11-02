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

int a[SZ];

int main() {
    srand(time(0));
    freopen("F.in","w",stdout);
        int n = rand() % 100 + 1,m = rand() % 1000 + 1;
        cout << n << " "<< m << endl;
        for(int i = 1;i <= n;i ++) a[i] = i;
        random_shuffle(a+1,a+1+n);
        for(int i = 1;i <= n;i ++) printf("%d ",a[i]);
}
