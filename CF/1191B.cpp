#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

bool check(string a,string b,string c) {
    if(a == b && b == c) return true;
    if(a[1] == b[1] && b[1] == c[1]) {
        int aa[] = {a[0],b[0],c[0]};
        sort(aa,aa+3);
        if(aa[1] == aa[0] + 1 && aa[2] == aa[1] + 1)
            return true;
    }
    return false;
}

bool check(string a,string b) {
    if(a == b) return true;
    if(a[1] == b[1]) {
        int aa[] = {a[0],b[0]};
        sort(aa,aa+2);
        if(aa[1] == aa[0] + 1 || aa[1] == aa[0] + 2)
            return true;
    }
    return false;
}

string a[44];

int main() {
    cin >> a[1] >> a[2] >> a[3];
    if(check(a[1],a[2],a[3])) return puts("0"),0;
    else {
        if(check(a[1],a[2]) || check(a[1],a[3]) || check(a[2],a[3]))
            return puts("1"),0;
    }
    puts("2");
}
