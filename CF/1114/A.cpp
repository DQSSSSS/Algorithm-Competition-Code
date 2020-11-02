#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 800*2*10+800+10;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int x,y,z,a,b,c;
bool check() {
    if(x > a) return false;
    a -= x;
    if(y > a + b) return false;
    if(z > a + b + c - y) return false;
    return true;
}

int main() {
    scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
    puts(check() ? "YES" : "NO");
}
