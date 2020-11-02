#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
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

int a[SZ];
string s1,s2;

bool isyuan(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool check() {
    if(s1.length() != s2.length()) return false;
    for(int i = 0;i < s1.length();i ++) {
        if(isyuan(s1[i]) != isyuan(s2[i])) return false;
    }
    return true;
}

int main() {
    cin >> s1 >> s2;
    if(check()) puts("Yes");
    else puts("No");
    return 0;
}
